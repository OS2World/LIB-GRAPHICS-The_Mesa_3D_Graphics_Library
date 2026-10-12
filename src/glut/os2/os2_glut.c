/*
 * os2_glut.c -- OS/2 Presentation Manager GLUT backend
 *               Mesa 7.11.2 / ArcaOS  (GCC 9.2, -Zomf)
 *
 * Single-window implementation.  Replaces the X11/GLX platform files
 * from src/glut/glx/ (glut_init, glut_event, glut_win, glut_swap, …).
 *
 * Windowing:  WinCreateStdWindow + WM_* message loop
 * GL context: WMesa API (WMesaCreateContext / MakeCurrent / SwapBuffers)
 * Timer:      WinStartTimer (10 ms poll) + per-entry expiry table
 */

#define INCL_WIN
#define INCL_GPI
#define INCL_DOS
#include <os2.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "glutint.h"      /* GL/gl.h + minimal GLUT types */
#include <GL/glut.h>      /* full GLUT API: constants, function prototypes */
#include "os2mesa.h"      /* WMesaCreateContext / MakeCurrent / SwapBuffers */

/* ====================================================================
 * Globals required by glut_util.c (declared extern in glutint.h)
 * ==================================================================== */

char *__glutProgramName  = NULL;
void (*__glutExitFunc)(int) = NULL;

/* ====================================================================
 * Internal state
 * ==================================================================== */

static HAB  g_hab        = NULLHANDLE;
static HMQ  g_hmq        = NULLHANDLE;
static HWND g_hwndFrame  = NULLHANDLE;
static HWND g_hwndClient = NULLHANDLE;
static WMesaContext g_ctx = NULL;

static unsigned int g_displayMode = GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH;
static int  g_winX = 100, g_winY = 100;
static int  g_winW = 300, g_winH = 300;
static int  g_needRedisplay  = 0;
static int  g_initialized    = 0;
static ULONG g_initTime      = 0;
static int  g_currentMods    = 0;   /* GLUT_ACTIVE_* during a callback */

/* ── Callbacks ───────────────────────────────────────────────────── */
static GLUTdisplayCB      g_display    = NULL;
static GLUTreshapeCB      g_reshape    = NULL;
static GLUTkeyboardCB     g_keyboard   = NULL;
static GLUTkeyboardCB     g_keyboardUp = NULL;
static GLUTspecialCB      g_special    = NULL;
static GLUTspecialCB      g_specialUp  = NULL;
static GLUTmouseCB        g_mouse      = NULL;
static GLUTmotionCB       g_motion     = NULL;
static GLUTpassiveCB      g_passive    = NULL;
static GLUTidleCB         g_idle       = NULL;
static GLUTvisibilityCB   g_visibility = NULL;
static GLUTwindowStatusCB g_winStatus  = NULL;
static GLUTentryCB        g_entry      = NULL;
static GLUTmenuStatusCB   g_menuStatus = NULL;
static GLUTmenuStateCB    g_menuState  = NULL;

/* ── Timer table ─────────────────────────────────────────────────── */
#define MAX_TIMERS  64
#define POLL_TIMER_ID  42       /* WinStartTimer ID used for tick */
#define POLL_TIMER_MS  10       /* polling resolution in ms */

typedef struct {
    GLUTtimerCB func;
    int         value;
    ULONG       expireMs;
    int         active;
} OS2GLUTtimer;

static OS2GLUTtimer g_timers[MAX_TIMERS];

static const char GLUT_WND_CLASS[] = "GLUTWND";

/* ====================================================================
 * Helpers
 * ==================================================================== */

/* VK_xxx → GLUT_KEY_xxx  (returns 0 for unknown / non-special key) */
static int vkToGlut(USHORT vk)
{
    switch (vk) {
    case VK_F1:       return GLUT_KEY_F1;
    case VK_F2:       return GLUT_KEY_F2;
    case VK_F3:       return GLUT_KEY_F3;
    case VK_F4:       return GLUT_KEY_F4;
    case VK_F5:       return GLUT_KEY_F5;
    case VK_F6:       return GLUT_KEY_F6;
    case VK_F7:       return GLUT_KEY_F7;
    case VK_F8:       return GLUT_KEY_F8;
    case VK_F9:       return GLUT_KEY_F9;
    case VK_F10:      return GLUT_KEY_F10;
    case VK_F11:      return GLUT_KEY_F11;
    case VK_F12:      return GLUT_KEY_F12;
    case VK_LEFT:     return GLUT_KEY_LEFT;
    case VK_RIGHT:    return GLUT_KEY_RIGHT;
    case VK_UP:       return GLUT_KEY_UP;
    case VK_DOWN:     return GLUT_KEY_DOWN;
    case VK_PAGEUP:   return GLUT_KEY_PAGE_UP;
    case VK_PAGEDOWN: return GLUT_KEY_PAGE_DOWN;
    case VK_HOME:     return GLUT_KEY_HOME;
    case VK_END:      return GLUT_KEY_END;
    case VK_INSERT:   return GLUT_KEY_INSERT;
    default:          return 0;
    }
}

/* Fire any timers whose deadline has passed */
static void processTimers(void)
{
    int i;
    ULONG now = WinGetCurrentTime(g_hab);
    for (i = 0; i < MAX_TIMERS; i++) {
        if (g_timers[i].active &&
            (LONG)(now - g_timers[i].expireMs) >= 0) {
            GLUTtimerCB f  = g_timers[i].func;
            int         val = g_timers[i].value;
            g_timers[i].active = 0;
            f(val);
        }
    }
}

/* Get mouse position in GLUT coords (y flipped, window-relative) */
static void getMousePos(int *mx, int *my)
{
    POINTL pt;
    WinQueryPointerPos(HWND_DESKTOP, &pt);
    if (g_hwndClient) WinMapWindowPoints(HWND_DESKTOP, g_hwndClient, &pt, 1);
    *mx = (int)pt.x;
    *my = g_winH - (int)pt.y;   /* PM y=0 at bottom → GLUT y=0 at top */
}

/* ====================================================================
 * Window procedure
 * ==================================================================== */

static MRESULT EXPENTRY WndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    switch (msg) {

    /* ── Paint / redisplay ────────────────────────────────────────── */
    case WM_PAINT: {
        RECTL rcl;
        HPS   hps = WinBeginPaint(hwnd, NULLHANDLE, &rcl);
        WinEndPaint(hps);
        g_needRedisplay = 1;        /* actual redraw happens in the loop */
        return 0;
    }

    /* ── Resize ───────────────────────────────────────────────────── */
    case WM_SIZE: {
        int nw = SHORT1FROMMP(mp2);
        int nh = SHORT2FROMMP(mp2);
        if (nw < 1) nw = 1;
        if (nh < 1) nh = 1;
        g_winW = nw;
        g_winH = nh;
        if (g_reshape) g_reshape(g_winW, g_winH);
        g_needRedisplay = 1;
        return 0;
    }

    /* ── Keyboard ─────────────────────────────────────────────────── */
    case WM_CHAR: {
        USHORT fs   = SHORT1FROMMP(mp1);   /* flags */
        USHORT chr  = SHORT1FROMMP(mp2);   /* character code */
        USHORT vkey = SHORT2FROMMP(mp2);   /* virtual key */
        int mx, my;
        getMousePos(&mx, &my);

        g_currentMods = 0;
        if (fs & KC_SHIFT) g_currentMods |= GLUT_ACTIVE_SHIFT;
        if (fs & KC_CTRL)  g_currentMods |= GLUT_ACTIVE_CTRL;
        if (fs & KC_ALT)   g_currentMods |= GLUT_ACTIVE_ALT;

        if (fs & KC_KEYUP) {
            /* key release */
            if ((fs & KC_VIRTUALKEY) && !(fs & KC_CHAR)) {
                int k = vkToGlut(vkey);
                if (k && g_specialUp) g_specialUp(k, mx, my);
            } else if ((fs & KC_CHAR) && g_keyboardUp) {
                g_keyboardUp((unsigned char)(chr & 0xFF), mx, my);
            }
        } else {
            /* key press */
            if ((fs & KC_VIRTUALKEY) && !(fs & KC_CHAR)) {
                int k = vkToGlut(vkey);
                if (k && g_special) g_special(k, mx, my);
            } else if (fs & KC_CHAR) {
                if (g_keyboard) g_keyboard((unsigned char)(chr & 0xFF), mx, my);
            }
        }
        g_currentMods = 0;
        return 0;
    }

    /* ── Mouse buttons ────────────────────────────────────────────── */
    case WM_BUTTON1DOWN:
    case WM_BUTTON2DOWN:
    case WM_BUTTON3DOWN:
    case WM_BUTTON1UP:
    case WM_BUTTON2UP:
    case WM_BUTTON3UP: {
        int button, state;
        int x = (int)SHORT1FROMMP(mp1);
        int y = g_winH - (int)SHORT2FROMMP(mp1);

        switch (msg) {
        case WM_BUTTON1DOWN: button=GLUT_LEFT_BUTTON;   state=GLUT_DOWN; break;
        case WM_BUTTON1UP:   button=GLUT_LEFT_BUTTON;   state=GLUT_UP;   break;
        case WM_BUTTON2DOWN: button=GLUT_MIDDLE_BUTTON; state=GLUT_DOWN; break;
        case WM_BUTTON2UP:   button=GLUT_MIDDLE_BUTTON; state=GLUT_UP;   break;
        case WM_BUTTON3DOWN: button=GLUT_RIGHT_BUTTON;  state=GLUT_DOWN; break;
        default:             button=GLUT_RIGHT_BUTTON;  state=GLUT_UP;   break;
        }
        if (g_mouse) g_mouse(button, state, x, y);
        /* capture / release mouse */
        WinSetCapture(HWND_DESKTOP,
                      (state == GLUT_DOWN) ? hwnd : NULLHANDLE);
        return 0;
    }

    /* ── Mouse motion ─────────────────────────────────────────────── */
    case WM_MOUSEMOVE: {
        int x = (int)SHORT1FROMMP(mp1);
        int y = g_winH - (int)SHORT2FROMMP(mp1);
        if ((WinGetKeyState(HWND_DESKTOP, VK_BUTTON1) & 0x8000) ||
            (WinGetKeyState(HWND_DESKTOP, VK_BUTTON2) & 0x8000) ||
            (WinGetKeyState(HWND_DESKTOP, VK_BUTTON3) & 0x8000)) {
            if (g_motion)  g_motion(x, y);
        } else {
            if (g_passive) g_passive(x, y);
        }
        return MRFROMSHORT(TRUE);
    }

    /* ── Timer tick ───────────────────────────────────────────────── */
    case WM_TIMER:
        processTimers();
        return 0;

    /* ── Close ────────────────────────────────────────────────────── */
    case WM_CLOSE:
        WinPostMsg(hwnd, WM_QUIT, 0, 0);
        return 0;

    default:
        return WinDefWindowProc(hwnd, msg, mp1, mp2);
    }
}

/* ====================================================================
 * glutInit
 * ==================================================================== */

/* OS/2 starts threads with the x87 control word at 0x0362, i.e. the
 * invalid-operation, divide-by-zero, overflow and underflow exceptions
 * UNMASKED.  Mesa and libm (cosf, sinf, ...) rely on the C/IEEE default of
 * all exceptions masked, so a pending exception shows up as SIGFPE inside
 * libc (LDMXCSR + WAIT).  Clear pending state and mask everything. */
static void maskFpuExceptions(void)
{
    unsigned int mx = 0x1F80;       /* default MXCSR: all SSE exceptions masked */
    /* fninit: empties the x87 register stack (stale entries make later
     * loads overflow to NaN), clears status and sets CW = 0x037F. */
    __asm__ volatile ("fninit");
    __asm__ volatile ("ldmxcsr %0" : : "m"(mx));
}

void GLUTAPIENTRY glutInit(int *argcp, char **argv)
{
    maskFpuExceptions();
    if (g_initialized) return;
    g_initialized = 1;

    if (argcp && *argcp > 0 && argv && argv[0])
        __glutProgramName = argv[0];

    g_hab = WinInitialize(0);
    if (!g_hab) {
        fprintf(stderr, "GLUT: WinInitialize failed\n");
        exit(1);
    }
    g_hmq = WinCreateMsgQueue(g_hab, 0);
    if (!g_hmq) {
        fprintf(stderr, "GLUT: WinCreateMsgQueue failed\n");
        exit(1);
    }
    g_initTime = WinGetCurrentTime(g_hab);
    memset(g_timers, 0, sizeof(g_timers));
}

void GLUTAPIENTRY __glutInitWithExit(int *argcp, char **argv,
                                     void (*exitfunc)(int))
{
    __glutExitFunc = exitfunc;
    glutInit(argcp, argv);
}

/* ====================================================================
 * Display mode / initial window parameters
 * ==================================================================== */

void GLUTAPIENTRY glutInitDisplayMode(unsigned int mode)
{
    g_displayMode = mode;
}

void GLUTAPIENTRY glutInitDisplayString(const char *str)
{
    (void)str;
}

void GLUTAPIENTRY glutInitWindowPosition(int x, int y)
{
    g_winX = x;
    g_winY = y;
}

void GLUTAPIENTRY glutInitWindowSize(int width, int height)
{
    if (width  > 0) g_winW = width;
    if (height > 0) g_winH = height;
}

/* ====================================================================
 * glutCreateWindow
 * ==================================================================== */

int GLUTAPIENTRY glutCreateWindow(const char *title)
{
    ULONG fcf;
    LONG  desktopH;

    if (!g_initialized) glutInit(NULL, NULL);

    WinRegisterClass(g_hab, (PSZ)GLUT_WND_CLASS, WndProc,
                     CS_SIZEREDRAW | CS_MOVENOTIFY, 0);

    fcf = FCF_TITLEBAR | FCF_SYSMENU | FCF_SIZEBORDER |
          FCF_MINMAX   | FCF_TASKLIST;

    g_hwndFrame = WinCreateStdWindow(
        HWND_DESKTOP, 0, &fcf,
        (PSZ)GLUT_WND_CLASS, (PSZ)(title ? title : "GLUT"),
        0, NULLHANDLE, 1, &g_hwndClient);

    if (!g_hwndFrame) {
        fprintf(stderr, "GLUT: WinCreateStdWindow failed (err 0x%lx)\n",
                WinGetLastError(g_hab));
        exit(1);
    }

    /* Convert GLUT top-left origin to PM bottom-left origin.
       Add ~30 px for the title bar height so the client area is g_winH. */
    desktopH = WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN);
    WinSetWindowPos(g_hwndFrame, HWND_TOP,
                    g_winX,
                    desktopH - g_winY - g_winH - 30,
                    g_winW, g_winH + 30,
                    SWP_MOVE | SWP_SIZE | SWP_SHOW | SWP_ACTIVATE);

    /* Create the WMesa rendering context */
    {
        HPS        hps   = WinGetPS(g_hwndClient);
        GLboolean  db    = (g_displayMode & GLUT_DOUBLE) ? GL_TRUE : GL_FALSE;
        GLboolean  alpha = (g_displayMode & GLUT_ALPHA)  ? GL_TRUE : GL_FALSE;
        g_ctx = WMesaCreateContext(g_hwndClient, hps, g_hab, db, alpha);
        WinReleasePS(hps);
    }
    if (!g_ctx) {
        fprintf(stderr, "GLUT: WMesaCreateContext failed\n");
        exit(1);
    }
    WMesaMakeCurrent(g_ctx, g_hwndClient);

    /* Kick off the timer-poll tick */
    WinStartTimer(g_hab, g_hwndClient, POLL_TIMER_ID, POLL_TIMER_MS);

    /* PM window/driver creation may have reset the FPU control word */
    maskFpuExceptions();

    return 1;
}

int GLUTAPIENTRY __glutCreateWindowWithExit(const char *title,
                                            void (*exitfunc)(int))
{
    __glutExitFunc = exitfunc;
    return glutCreateWindow(title);
}

int GLUTAPIENTRY glutCreateSubWindow(int win, int x, int y, int w, int h)
{
    (void)win; (void)x; (void)y; (void)w; (void)h;
    return 0;
}

void GLUTAPIENTRY glutDestroyWindow(int win)
{
    (void)win;
    if (g_ctx)       { WMesaDestroyContext(g_ctx); g_ctx = NULL; }
    if (g_hwndFrame) { WinDestroyWindow(g_hwndFrame); g_hwndFrame = NULLHANDLE; }
}

/* ====================================================================
 * glutMainLoop
 * ==================================================================== */

void GLUTAPIENTRY glutMainLoop(void)
{
    QMSG  qmsg;
    ULONG frameStart = WinGetCurrentTime(g_hab);
    ULONG FRAME_MS   = 33;      /* ~30 fps cap for idle-driven animation */
    {
        /* GLUT_FPS=<1..1000> overrides the frame-rate cap */
        const char *e = getenv("GLUT_FPS");
        int fps = e ? atoi(e) : 0;
        if (fps >= 1 && fps <= 1000) FRAME_MS = (ULONG)(1000 / fps);
    }

    /* Issue initial reshape + redisplay */
    if (g_reshape && g_winW > 0 && g_winH > 0)
        g_reshape(g_winW, g_winH);
    glutPostRedisplay();

    for (;;) {
        if (g_idle || g_needRedisplay) {
            /* Non-blocking: drain all pending messages */
            while (WinPeekMsg(g_hab, &qmsg, NULLHANDLE, 0, 0, PM_REMOVE)) {
                if (qmsg.msg == WM_QUIT) goto done;
                WinDispatchMsg(g_hab, &qmsg);
            }
        } else {
            /* Blocking: wait for the next message */
            if (!WinGetMsg(g_hab, &qmsg, NULLHANDLE, 0, 0)) break;
            if (qmsg.msg == WM_QUIT) break;
            WinDispatchMsg(g_hab, &qmsg);
        }

        processTimers();

        if (g_idle) g_idle();

        if (g_needRedisplay && g_display && g_ctx) {
            g_needRedisplay = 0;
            WMesaMakeCurrent(g_ctx, g_hwndClient);
            g_display();
        }

        /* An idle callback (or continuous redisplay) keeps us in the
         * non-blocking branch above, which would otherwise spin at 100%
         * CPU.  Cap the loop at ~60 frames/s and yield the remainder. */
        if (g_idle || g_needRedisplay) {
            ULONG elapsed = WinGetCurrentTime(g_hab) - frameStart;
            if (elapsed < FRAME_MS)
                DosSleep(FRAME_MS - elapsed);
            else
                DosSleep(1);
        }
        frameStart = WinGetCurrentTime(g_hab);
    }

done:
    WinStopTimer(g_hab, g_hwndClient, POLL_TIMER_ID);
    if (g_ctx)       { WMesaDestroyContext(g_ctx); g_ctx = NULL; }
    if (g_hwndFrame) { WinDestroyWindow(g_hwndFrame); g_hwndFrame = NULLHANDLE; }
    WinDestroyMsgQueue(g_hmq); g_hmq = NULLHANDLE;
    WinTerminate(g_hab);    g_hab = NULLHANDLE;
}

/* ====================================================================
 * Swap / redisplay
 * ==================================================================== */

void GLUTAPIENTRY glutSwapBuffers(void)
{
    if (g_hwndClient) WMesaSwapBuffers(g_hwndClient);
}

void GLUTAPIENTRY glutPostRedisplay(void)
{
    g_needRedisplay = 1;
}

void GLUTAPIENTRY glutPostWindowRedisplay(int win)
{
    (void)win;
    g_needRedisplay = 1;
}

/* ====================================================================
 * Window management
 * ==================================================================== */

int GLUTAPIENTRY glutGetWindow(void)
{
    return (g_hwndClient != NULLHANDLE) ? 1 : 0;
}

void GLUTAPIENTRY glutSetWindow(int win) { (void)win; }

void GLUTAPIENTRY glutSetWindowTitle(const char *title)
{
    if (g_hwndFrame) WinSetWindowText(g_hwndFrame, (PSZ)title);
}

void GLUTAPIENTRY glutSetIconTitle(const char *title) { (void)title; }

void GLUTAPIENTRY glutPositionWindow(int x, int y)
{
    if (g_hwndFrame) {
        LONG dh = WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN);
        WinSetWindowPos(g_hwndFrame, NULLHANDLE,
                        x, dh - y - g_winH - 30, 0, 0, SWP_MOVE);
        g_winX = x; g_winY = y;
    }
}

void GLUTAPIENTRY glutReshapeWindow(int width, int height)
{
    if (g_hwndFrame) {
        WinSetWindowPos(g_hwndFrame, NULLHANDLE,
                        0, 0, width, height + 30, SWP_SIZE);
        g_winW = width; g_winH = height;
    }
}

void GLUTAPIENTRY glutPopWindow(void)
{
    if (g_hwndFrame)
        WinSetWindowPos(g_hwndFrame, HWND_TOP, 0,0,0,0, SWP_ZORDER);
}

void GLUTAPIENTRY glutPushWindow(void)
{
    if (g_hwndFrame)
        WinSetWindowPos(g_hwndFrame, HWND_BOTTOM, 0,0,0,0, SWP_ZORDER);
}

void GLUTAPIENTRY glutIconifyWindow(void)
{
    if (g_hwndFrame)
        WinSetWindowPos(g_hwndFrame, NULLHANDLE, 0,0,0,0, SWP_MINIMIZE);
}

void GLUTAPIENTRY glutShowWindow(void)
{
    if (g_hwndFrame)
        WinSetWindowPos(g_hwndFrame, HWND_TOP, 0,0,0,0,
                        SWP_SHOW | SWP_ZORDER);
}

void GLUTAPIENTRY glutHideWindow(void)
{
    if (g_hwndFrame) WinShowWindow(g_hwndFrame, FALSE);
}

void GLUTAPIENTRY glutFullScreen(void)
{
    if (g_hwndFrame) {
        LONG sw = WinQuerySysValue(HWND_DESKTOP, SV_CXSCREEN);
        LONG sh = WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN);
        WinSetWindowPos(g_hwndFrame, HWND_TOP, 0, 0, sw, sh,
                        SWP_MOVE | SWP_SIZE | SWP_SHOW | SWP_ZORDER);
    }
}

void GLUTAPIENTRY glutSetCursor(int cursor)
{
    LONG   sptrid;
    HPOINTER hptr;

    switch (cursor) {
    case GLUT_CURSOR_NONE:
        WinSetPointer(HWND_DESKTOP, NULLHANDLE);
        return;
    case GLUT_CURSOR_WAIT:              sptrid = SPTR_WAIT;     break;
    case GLUT_CURSOR_TEXT:              sptrid = SPTR_TEXT;     break;
    case GLUT_CURSOR_LEFT_RIGHT:        sptrid = SPTR_SIZEWE;   break;
    case GLUT_CURSOR_UP_DOWN:           sptrid = SPTR_SIZENS;   break;
    case GLUT_CURSOR_LEFT_SIDE:         sptrid = SPTR_SIZEWE;   break;
    case GLUT_CURSOR_RIGHT_SIDE:        sptrid = SPTR_SIZEWE;   break;
    case GLUT_CURSOR_TOP_SIDE:          sptrid = SPTR_SIZENS;   break;
    case GLUT_CURSOR_BOTTOM_SIDE:       sptrid = SPTR_SIZENS;   break;
    case GLUT_CURSOR_TOP_LEFT_CORNER:   sptrid = SPTR_SIZENWSE; break;
    case GLUT_CURSOR_BOTTOM_RIGHT_CORNER: sptrid = SPTR_SIZENWSE; break;
    case GLUT_CURSOR_TOP_RIGHT_CORNER:  sptrid = SPTR_SIZENESW; break;
    case GLUT_CURSOR_BOTTOM_LEFT_CORNER: sptrid = SPTR_SIZENESW; break;
    /* GLUT_CURSOR_CROSSHAIR, GLUT_CURSOR_FULL_CROSSHAIR: no OS/2 system crosshair */
    default:                            sptrid = SPTR_ARROW;    break;
    }
    hptr = WinQuerySysPointer(HWND_DESKTOP, sptrid, FALSE);
    WinSetPointer(HWND_DESKTOP, hptr);
}

void GLUTAPIENTRY glutWarpPointer(int x, int y)
{
    if (g_hwndClient) {
        POINTL pt;
        pt.x = x;
        pt.y = g_winH - y;    /* GLUT top → PM bottom */
        WinMapWindowPoints(g_hwndClient, HWND_DESKTOP, &pt, 1);
        WinSetPointerPos(HWND_DESKTOP, pt.x, pt.y);
    }
}

/* ====================================================================
 * Callback registration
 * ==================================================================== */

void GLUTAPIENTRY glutDisplayFunc(void (*f)(void))
                                        { g_display    = f; }
void GLUTAPIENTRY glutReshapeFunc(void (*f)(int,int))
                                        { g_reshape    = f; }
void GLUTAPIENTRY glutKeyboardFunc(void (*f)(unsigned char,int,int))
                                        { g_keyboard   = f; }
void GLUTAPIENTRY glutKeyboardUpFunc(void (*f)(unsigned char,int,int))
                                        { g_keyboardUp = f; }
void GLUTAPIENTRY glutSpecialFunc(void (*f)(int,int,int))
                                        { g_special    = f; }
void GLUTAPIENTRY glutSpecialUpFunc(void (*f)(int,int,int))
                                        { g_specialUp  = f; }
void GLUTAPIENTRY glutMouseFunc(void (*f)(int,int,int,int))
                                        { g_mouse      = f; }
void GLUTAPIENTRY glutMotionFunc(void (*f)(int,int))
                                        { g_motion     = f; }
void GLUTAPIENTRY glutPassiveMotionFunc(void (*f)(int,int))
                                        { g_passive    = f; }
void GLUTAPIENTRY glutEntryFunc(void (*f)(int))
                                        { g_entry      = f; }
void GLUTAPIENTRY glutVisibilityFunc(void (*f)(int))
                                        { g_visibility = f; }
void GLUTAPIENTRY glutWindowStatusFunc(void (*f)(int))
                                        { g_winStatus  = f; }
void GLUTAPIENTRY glutIdleFunc(void (*f)(void))
                                        { g_idle       = f; }
void GLUTAPIENTRY glutMenuStateFunc(void (*f)(int))
                                        { g_menuState  = f; }
void GLUTAPIENTRY glutMenuStatusFunc(void (*f)(int,int,int))
                                        { g_menuStatus = f; }
void GLUTAPIENTRY glutOverlayDisplayFunc(void (*f)(void)) { (void)f; }

void GLUTAPIENTRY glutTimerFunc(unsigned int millis,
                                void (*func)(int), int value)
{
    int i;
    ULONG now = g_hab ? WinGetCurrentTime(g_hab) : 0;
    for (i = 0; i < MAX_TIMERS; i++) {
        if (!g_timers[i].active) {
            g_timers[i].func     = func;
            g_timers[i].value    = value;
            g_timers[i].expireMs = now + millis;
            g_timers[i].active   = 1;
            return;
        }
    }
    fprintf(stderr, "GLUT: timer table full (> %d entries)\n", MAX_TIMERS);
}

/* ── Unsupported input device stubs ─────────────────────────────── */
void GLUTAPIENTRY glutSpaceballMotionFunc(void (*f)(int,int,int))     {(void)f;}
void GLUTAPIENTRY glutSpaceballRotateFunc(void (*f)(int,int,int))     {(void)f;}
void GLUTAPIENTRY glutSpaceballButtonFunc(void (*f)(int,int))         {(void)f;}
void GLUTAPIENTRY glutButtonBoxFunc(void (*f)(int,int))               {(void)f;}
void GLUTAPIENTRY glutDialsFunc(void (*f)(int,int))                   {(void)f;}
void GLUTAPIENTRY glutTabletMotionFunc(void (*f)(int,int))            {(void)f;}
void GLUTAPIENTRY glutTabletButtonFunc(void (*f)(int,int,int,int))    {(void)f;}
void GLUTAPIENTRY glutJoystickFunc(void (*f)(unsigned int,int,int,int),
                                   int poll) { (void)f; (void)poll; }

/* ====================================================================
 * glutGet / glutDeviceGet / glutLayerGet / glutGetModifiers
 * ==================================================================== */

int GLUTAPIENTRY glutGet(GLenum type)
{
    switch (type) {
    case GLUT_WINDOW_X:              return g_winX;
    case GLUT_WINDOW_Y:              return g_winY;
    case GLUT_WINDOW_WIDTH:          return g_winW;
    case GLUT_WINDOW_HEIGHT:         return g_winH;
    case GLUT_WINDOW_BUFFER_SIZE:    return 32;
    case GLUT_WINDOW_DEPTH_SIZE:     return 16;
    case GLUT_WINDOW_RED_SIZE:       return 8;
    case GLUT_WINDOW_GREEN_SIZE:     return 8;
    case GLUT_WINDOW_BLUE_SIZE:      return 8;
    case GLUT_WINDOW_ALPHA_SIZE:     return 0;
    case GLUT_WINDOW_ACCUM_RED_SIZE:
    case GLUT_WINDOW_ACCUM_GREEN_SIZE:
    case GLUT_WINDOW_ACCUM_BLUE_SIZE:
    case GLUT_WINDOW_ACCUM_ALPHA_SIZE: return 0;
    case GLUT_WINDOW_STENCIL_SIZE:   return 0;
    case GLUT_WINDOW_DOUBLEBUFFER:
        return (g_displayMode & GLUT_DOUBLE) ? 1 : 0;
    case GLUT_WINDOW_RGBA:           return 1;
    case GLUT_WINDOW_PARENT:         return 0;
    case GLUT_WINDOW_NUM_CHILDREN:   return 0;
    case GLUT_WINDOW_COLORMAP_SIZE:  return 0;
    case GLUT_WINDOW_NUM_SAMPLES:    return 0;
    case GLUT_WINDOW_STEREO:         return 0;
    case GLUT_WINDOW_CURSOR:         return GLUT_CURSOR_INHERIT;
    case GLUT_SCREEN_WIDTH:
        return g_hab ? (int)WinQuerySysValue(HWND_DESKTOP, SV_CXSCREEN) : 0;
    case GLUT_SCREEN_HEIGHT:
        return g_hab ? (int)WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN) : 0;
    case GLUT_SCREEN_WIDTH_MM:
        return g_hab ? (int)(WinQuerySysValue(HWND_DESKTOP,SV_CXSCREEN)*25.4/96.0) : 0;
    case GLUT_SCREEN_HEIGHT_MM:
        return g_hab ? (int)(WinQuerySysValue(HWND_DESKTOP,SV_CYSCREEN)*25.4/96.0) : 0;
    case GLUT_MENU_NUM_ITEMS:        return 0;
    case GLUT_DISPLAY_MODE_POSSIBLE: return 1;
    case GLUT_INIT_WINDOW_X:         return g_winX;
    case GLUT_INIT_WINDOW_Y:         return g_winY;
    case GLUT_INIT_WINDOW_WIDTH:     return g_winW;
    case GLUT_INIT_WINDOW_HEIGHT:    return g_winH;
    case GLUT_INIT_DISPLAY_MODE:     return (int)g_displayMode;
    case GLUT_ELAPSED_TIME:
        return g_hab ? (int)(WinGetCurrentTime(g_hab) - g_initTime) : 0;
    case GLUT_WINDOW_FORMAT_ID:      return 0;
    case GLUT_GAME_MODE_ACTIVE:      return 0;
    default:                         return -1;
    }
}

int GLUTAPIENTRY glutDeviceGet(GLenum type)
{
    switch (type) {
    case GLUT_HAS_KEYBOARD:             return 1;
    case GLUT_HAS_MOUSE:                return 1;
    case GLUT_NUM_MOUSE_BUTTONS:        return 3;
    case GLUT_HAS_SPACEBALL:            return 0;
    case GLUT_HAS_DIAL_AND_BUTTON_BOX:  return 0;
    case GLUT_HAS_TABLET:               return 0;
    case GLUT_NUM_SPACEBALL_BUTTONS:    return 0;
    case GLUT_NUM_BUTTON_BOX_BUTTONS:   return 0;
    case GLUT_NUM_DIALS:                return 0;
    case GLUT_NUM_TABLET_BUTTONS:       return 0;
    case GLUT_DEVICE_IGNORE_KEY_REPEAT: return 0;
    case GLUT_DEVICE_KEY_REPEAT:        return 0;
    case GLUT_HAS_JOYSTICK:             return 0;
    case GLUT_JOYSTICK_POLL_RATE:       return 0;
    case GLUT_JOYSTICK_BUTTONS:         return 0;
    case GLUT_JOYSTICK_AXES:            return 0;
    default:                            return -1;
    }
}

int GLUTAPIENTRY glutGetModifiers(void)
{
    return g_currentMods;
}

int GLUTAPIENTRY glutLayerGet(GLenum type)
{
    switch (type) {
    case GLUT_OVERLAY_POSSIBLE:  return 0;
    case GLUT_LAYER_IN_USE:      return GLUT_NORMAL;
    case GLUT_HAS_OVERLAY:       return 0;
    case GLUT_TRANSPARENT_INDEX: return -1;
    case GLUT_NORMAL_DAMAGED:    return 0;
    case GLUT_OVERLAY_DAMAGED:   return 0;
    default:                     return -1;
    }
}

/* ====================================================================
 * Color index (stubs — we always use RGBA)
 * ==================================================================== */

void GLUTAPIENTRY glutSetColor(int ndx, GLfloat r, GLfloat g, GLfloat b)
    { (void)ndx; (void)r; (void)g; (void)b; }

GLfloat GLUTAPIENTRY glutGetColor(int ndx, int component)
    { (void)ndx; (void)component; return -1.0f; }

void GLUTAPIENTRY glutCopyColormap(int win) { (void)win; }

/* ====================================================================
 * Overlay stubs
 * ==================================================================== */

void GLUTAPIENTRY glutEstablishOverlay(void)                   {}
void GLUTAPIENTRY glutRemoveOverlay(void)                       {}
void GLUTAPIENTRY glutUseLayer(GLenum layer)                    { (void)layer; }
void GLUTAPIENTRY glutPostOverlayRedisplay(void)                {}
void GLUTAPIENTRY glutPostWindowOverlayRedisplay(int w)         { (void)w; }
void GLUTAPIENTRY glutShowOverlay(void)                         {}
void GLUTAPIENTRY glutHideOverlay(void)                         {}

/* ====================================================================
 * Menu stubs (no PM popup menu integration in v1)
 * ==================================================================== */

int  GLUTAPIENTRY glutCreateMenu(void (*f)(int))                { (void)f; return 1; }
int  GLUTAPIENTRY __glutCreateMenuWithExit(void (*f)(int),
                                           void (*ef)(int))
     { (void)ef; return glutCreateMenu(f); }
void GLUTAPIENTRY glutDestroyMenu(int m)                        { (void)m; }
int  GLUTAPIENTRY glutGetMenu(void)                             { return 1; }
void GLUTAPIENTRY glutSetMenu(int m)                            { (void)m; }
void GLUTAPIENTRY glutAddMenuEntry(const char *l, int v)        { (void)l; (void)v; }
void GLUTAPIENTRY glutAddSubMenu(const char *l, int s)          { (void)l; (void)s; }
void GLUTAPIENTRY glutChangeToMenuEntry(int i,const char *l,int v)
     { (void)i; (void)l; (void)v; }
void GLUTAPIENTRY glutChangeToSubMenu(int i, const char *l, int s)
     { (void)i; (void)l; (void)s; }
void GLUTAPIENTRY glutRemoveMenuItem(int i)                     { (void)i; }
void GLUTAPIENTRY glutAttachMenu(int b)                         { (void)b; }
void GLUTAPIENTRY glutDetachMenu(int b)                         { (void)b; }

/* ====================================================================
 * Video resize stubs
 * ==================================================================== */

int  GLUTAPIENTRY glutVideoResizeGet(GLenum p)                  { (void)p; return 0; }
void GLUTAPIENTRY glutSetupVideoResizing(void)                  {}
void GLUTAPIENTRY glutStopVideoResizing(void)                   {}
void GLUTAPIENTRY glutVideoResize(int x,int y,int w,int h)
     { (void)x; (void)y; (void)w; (void)h; }
void GLUTAPIENTRY glutVideoPan(int x, int y, int w, int h)
     { (void)x; (void)y; (void)w; (void)h; }

/* ====================================================================
 * Game mode stubs
 * ==================================================================== */

void GLUTAPIENTRY glutGameModeString(const char *s)             { (void)s; }
int  GLUTAPIENTRY glutEnterGameMode(void)                       { return 0; }
void GLUTAPIENTRY glutLeaveGameMode(void)                       {}
int  GLUTAPIENTRY glutGameModeGet(GLenum p)                     { (void)p; return 0; }

/* ====================================================================
 * Key-repeat / joystick stubs (referenced by glut_ext.c proc table)
 * ==================================================================== */

void GLUTAPIENTRY glutIgnoreKeyRepeat(int ignore)               { (void)ignore; }
void GLUTAPIENTRY glutSetKeyRepeat(int repeatMode)              { (void)repeatMode; }
void GLUTAPIENTRY glutForceJoystickFunc(void)                   {}
