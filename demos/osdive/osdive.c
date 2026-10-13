/* osdive.c -- OpenGL rendered to MEMORY with OSMesa, shown on screen with DIVE.
 *
 * This is the "software GL + DIVE" recipe for porting OpenGL programs (Quake-like
 * engines, ClassiCube, ...): the scene is rendered by Mesa into an ordinary
 * 32-bit memory buffer, and DIVE blits that buffer to the PM window, clipped to
 * the visible region and scaled to the window size by DIVE.
 *
 *   OSMesa:  RGBA/BGRA buffer in memory  (OSMESA_BGRA, rows top-down)
 *   DIVE:    FOURCC_BGR4 source buffer   ->  FOURCC_SCRN
 *
 * Usage:  osdive [width height]      internal render size, default 320 x 240.
 * Keys:   space pause, ESC quit.  Resize the window to see DIVE scale the image.
 *
 * The DIVE blitter handling follows the DIVEDemo sample (visible region
 * rectangles, WM_VRNDISABLED / WM_VRNENABLED).
 */
#define INCL_WIN
#define INCL_GPI
#define INCL_DOS
#define INCL_DOSMEMMGR
#define INCL_MM_OS2
#include <os2.h>
#include <mmioos2.h>
#include <dive.h>
#include <fourcc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/osmesa.h>

#define TIMER_ID   1
#define TIMER_MS   16
#define CLS_NAME   "OsDiveClient"

typedef struct {
    HAB   hab;
    HMQ   hmq;
    HWND  hwndFrame, hwndClient;
    HDIVE hDive;
    ULONG bufNum;
    PBYTE pix;                 /* OSMesa renders here, DIVE blits from here */
    ULONG w, h;                /* internal render size (width multiple of 8) */
    int   blitting;
    int   paused;
    float angle;
    int   frames;
    ULONG t0;
    OSMesaContext ctx;
    GLUquadric *quad;
} App;

static App A;

/* ---------------------------------------------------------------- GL --- */

static void init_gl(void)
{
    static const GLfloat lpos[4] = { 2.0f, 3.0f, 4.0f, 0.0f };
    glViewport(0, 0, (GLsizei)A.w, (GLsizei)A.h);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)A.w / (double)A.h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    A.quad = gluNewQuadric();
}

static void cube(void)
{
    static const GLfloat n[6][3] = { {0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0} };
    static const GLfloat v[6][4][3] = {
        {{-1,-1, 1},{ 1,-1, 1},{ 1, 1, 1},{-1, 1, 1}},
        {{ 1,-1,-1},{-1,-1,-1},{-1, 1,-1},{ 1, 1,-1}},
        {{ 1,-1, 1},{ 1,-1,-1},{ 1, 1,-1},{ 1, 1, 1}},
        {{-1,-1,-1},{-1,-1, 1},{-1, 1, 1},{-1, 1,-1}},
        {{-1, 1, 1},{ 1, 1, 1},{ 1, 1,-1},{-1, 1,-1}},
        {{-1,-1,-1},{ 1,-1,-1},{ 1,-1, 1},{-1,-1, 1}} };
    static const GLfloat col[6][3] = { {1,.3f,.2f},{.3f,.5f,1},{.3f,1,.4f},{1,.9f,.2f},{.9f,.3f,1},{.2f,1,1} };
    int i, j;
    glBegin(GL_QUADS);
    for (i = 0; i < 6; i++) {
        glColor3fv(col[i]);
        glNormal3fv(n[i]);
        for (j = 0; j < 4; j++) glVertex3fv(v[i][j]);
    }
    glEnd();
}

static void render(void)
{
    glClearColor(0.05f, 0.06f, 0.12f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -6.0f);
    glRotatef(20.0f, 1, 0, 0);
    glPushMatrix();
    glRotatef(A.angle, 0.3f, 1.0f, 0.2f);
    cube();
    glPopMatrix();
    glPushMatrix();                              /* an orbiting sphere */
    glRotatef(A.angle * 1.7f, 0, 1, 0);
    glTranslatef(2.6f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.85f, 0.2f);
    gluSphere(A.quad, 0.6, 20, 14);
    glPopMatrix();
    glFinish();                                  /* pixels are now in A.pix */
}

/* --------------------------------------------------------------- DIVE --- */

static ULONG collect_visible_rects(HWND hwnd, RECTL *out, ULONG max)
{
    HPS hps = WinGetPS(hwnd);
    HRGN hrgn;
    RGNRECT ctl;

    if (!hps) return 0;
    hrgn = GpiCreateRegion(hps, 0L, NULL);
    if (hrgn == (HRGN)HRGN_ERROR) { WinReleasePS(hps); return 0; }
    if (WinQueryVisibleRegion(hwnd, hrgn) == (ULONG)RGN_ERROR) {
        GpiDestroyRegion(hps, hrgn); WinReleasePS(hps); return 0;
    }
    memset(&ctl, 0, sizeof ctl);
    ctl.ircStart = 0;
    ctl.crc = max;
    ctl.ulDirection = RECTDIR_LFRT_TOPBOT;
    if (!GpiQueryRegionRects(hps, hrgn, NULL, &ctl, out)) ctl.crcReturned = 0;
    GpiDestroyRegion(hps, hrgn);
    WinReleasePS(hps);
    return ctl.crcReturned;
}

/* (Re)arm the blitter for the current window geometry.  The destination size
 * is the client size, so DIVE scales the (smaller) render buffer to fit. */
static void setup_blitter(void)
{
    RECTL  vis[50], client;
    ULONG  n;
    POINTL org = { 0, 0 };
    SETUP_BLITTER s;

    A.blitting = 0;
    WinQueryWindowRect(A.hwndClient, &client);
    n = collect_visible_rects(A.hwndClient, vis, 50);
    if (n == 0 || client.xRight <= 0 || client.yTop <= 0) {
        DiveSetupBlitter(A.hDive, NULL);
        return;
    }
    memset(&s, 0, sizeof s);
    s.ulStructLen       = sizeof s;
    s.fInvert           = FALSE;
    s.fccSrcColorFormat = FOURCC_BGR4;
    s.ulSrcWidth        = A.w;
    s.ulSrcHeight       = A.h;
    s.ulSrcPosX         = 0;
    s.ulSrcPosY         = 0;
    s.ulDitherType      = 0;
    s.fccDstColorFormat = FOURCC_SCRN;
    s.ulDstWidth        = (ULONG)client.xRight;
    s.ulDstHeight       = (ULONG)client.yTop;
    s.lDstPosX          = 0;
    s.lDstPosY          = 0;
    WinMapWindowPoints(A.hwndClient, HWND_DESKTOP, &org, 1);
    s.lScreenPosX       = org.x;
    s.lScreenPosY       = org.y;
    s.ulNumDstRects     = n;
    s.pVisDstRects      = vis;
    if (DiveSetupBlitter(A.hDive, &s) == DIVE_SUCCESS)
        A.blitting = 1;
}

static int dive_start(void)
{
    DIVE_CAPS caps;
    FOURCC    fmts[32];
    ULONG     rc;

    memset(&caps, 0, sizeof caps);
    memset(fmts, 0, sizeof fmts);
    caps.ulStructLen    = sizeof caps;
    caps.ulFormatLength = sizeof fmts;
    caps.pFormatData    = fmts;
    rc = DiveQueryCaps(&caps, DIVE_BUFFER_SCREEN);
    if (rc != DIVE_SUCCESS) { fprintf(stderr, "DiveQueryCaps failed: 0x%lx\n", rc); return 0; }
    if (caps.ulDepth < 15) { fprintf(stderr, "needs a 15+ bit colour desktop\n"); return 0; }
    rc = DiveOpen(&A.hDive, FALSE, NULL);
    if (rc != DIVE_SUCCESS) { fprintf(stderr, "DiveOpen failed: 0x%lx\n", rc); return 0; }

    /* the pixel buffer is ours (DosAllocMem); DIVE just associates with it */
    rc = DosAllocMem((PPVOID)&A.pix, A.w * A.h * 4,
                     PAG_COMMIT | PAG_READ | PAG_WRITE);
    if (rc) { fprintf(stderr, "DosAllocMem failed: %lu\n", rc); return 0; }
    memset(A.pix, 0, A.w * A.h * 4);
    rc = DiveAllocImageBuffer(A.hDive, &A.bufNum, FOURCC_BGR4,
                              A.w, A.h, 0, A.pix);
    if (rc != DIVE_SUCCESS) { fprintf(stderr, "DiveAllocImageBuffer failed: 0x%lx\n", rc); return 0; }
    return 1;
}

static void dive_stop(void)
{
    if (A.hDive) {
        DiveSetupBlitter(A.hDive, NULL);
        DiveFreeImageBuffer(A.hDive, A.bufNum);
        DiveClose(A.hDive);
        A.hDive = 0;
    }
    if (A.pix) { DosFreeMem(A.pix); A.pix = NULL; }
}

/* ------------------------------------------------------------- window --- */

static void frame(void)
{
    ULONG now;
    render();
    if (A.blitting)
        DiveBlitImage(A.hDive, A.bufNum, DIVE_BUFFER_SCREEN);
    A.frames++;
    now = WinGetCurrentTime(A.hab);
    if (now - A.t0 >= 1000) {
        char title[96];
        sprintf(title, "Mesa OSMesa + DIVE - %lux%lu buffer - %d fps",
                A.w, A.h, (int)(A.frames * 1000UL / (now - A.t0)));
        WinSetWindowText(A.hwndFrame, (PCSZ)title);
        A.frames = 0;
        A.t0 = now;
    }
}

static MRESULT EXPENTRY ClientProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    switch (msg) {
    case WM_CREATE:
        WinSetVisibleRegionNotify(hwnd, TRUE);
        WinPostMsg(hwnd, WM_VRNENABLED, 0L, 0L);
        return 0;
    case WM_VRNDISABLED:
        DiveSetupBlitter(A.hDive, NULL);
        A.blitting = 0;
        return 0;
    case WM_VRNENABLED:
    case WM_SIZE:
    case WM_MOVE:
        if (A.hDive) setup_blitter();
        return 0;
    case WM_TIMER:
        if (!A.paused) { A.angle += 1.2f; frame(); }
        return 0;
    case WM_PAINT: {
        RECTL r;
        HPS hps = WinBeginPaint(hwnd, NULLHANDLE, &r);
        WinEndPaint(hps);
        if (A.blitting) DiveBlitImage(A.hDive, A.bufNum, DIVE_BUFFER_SCREEN);
        return 0;
    }
    case WM_CHAR:
        if (!(SHORT1FROMMP(mp1) & KC_KEYUP)) {
            if ((SHORT1FROMMP(mp1) & KC_VIRTUALKEY) && SHORT2FROMMP(mp2) == VK_ESC)
                WinPostMsg(hwnd, WM_QUIT, 0, 0);
            else if ((SHORT1FROMMP(mp1) & KC_CHAR) && SHORT1FROMMP(mp2) == ' ')
                A.paused = !A.paused;
        }
        return (MRESULT)TRUE;
    case WM_CLOSE:
        WinPostMsg(hwnd, WM_QUIT, 0, 0);
        return 0;
    }
    return WinDefWindowProc(hwnd, msg, mp1, mp2);
}

int main(int argc, char **argv)
{
    ULONG fcf = FCF_TITLEBAR | FCF_SYSMENU | FCF_SIZEBORDER | FCF_MINMAX |
                FCF_TASKLIST | FCF_SHELLPOSITION;
    QMSG qmsg;

    A.w = 320; A.h = 240;
    if (argc >= 3) { A.w = (ULONG)atoi(argv[1]); A.h = (ULONG)atoi(argv[2]); }
    A.w &= ~7UL;                                   /* DIVE wants width % 8 == 0 */
    if (A.w < 64 || A.h < 48 || A.w > 2048 || A.h > 2048) { A.w = 320; A.h = 240; }

    A.hab = WinInitialize(0);
    A.hmq = WinCreateMsgQueue(A.hab, 0);
    if (!A.hab || !A.hmq) return 1;

    if (!dive_start()) { dive_stop(); return 1; }

    /* OSMesa: render into A.pix, BGRA byte order, first row = top of image */
    A.ctx = OSMesaCreateContextExt(OSMESA_BGRA, 16, 0, 0, NULL);
    if (!A.ctx || !OSMesaMakeCurrent(A.ctx, A.pix, GL_UNSIGNED_BYTE,
                                     (GLsizei)A.w, (GLsizei)A.h)) {
        fprintf(stderr, "OSMesa setup failed\n");
        dive_stop();
        return 1;
    }
    OSMesaPixelStore(OSMESA_Y_UP, 0);
    init_gl();

    WinRegisterClass(A.hab, (PSZ)CLS_NAME, ClientProc, CS_SIZEREDRAW | CS_MOVENOTIFY, 0);
    A.hwndFrame = WinCreateStdWindow(HWND_DESKTOP, 0, &fcf, (PSZ)CLS_NAME,
                                     (PSZ)"Mesa OSMesa + DIVE", 0, NULLHANDLE, 1,
                                     &A.hwndClient);
    if (!A.hwndFrame) { fprintf(stderr, "window creation failed\n"); dive_stop(); return 1; }
    WinSetWindowPos(A.hwndFrame, HWND_TOP, 120, 120,
                    (LONG)(A.w * 2 + 8), (LONG)(A.h * 2 + 32),
                    SWP_MOVE | SWP_SIZE | SWP_SHOW | SWP_ACTIVATE);

    A.t0 = WinGetCurrentTime(A.hab);
    WinStartTimer(A.hab, A.hwndClient, TIMER_ID, TIMER_MS);
    while (WinGetMsg(A.hab, &qmsg, NULLHANDLE, 0, 0))
        WinDispatchMsg(A.hab, &qmsg);
    WinStopTimer(A.hab, A.hwndClient, TIMER_ID);

    WinDestroyWindow(A.hwndFrame);
    gluDeleteQuadric(A.quad);
    OSMesaDestroyContext(A.ctx);
    dive_stop();
    WinDestroyMsgQueue(A.hmq);
    WinTerminate(A.hab);
    return 0;
}
