/* osmesa_test.c -- headless OSMesa smoke test (no window, no PM needed).
 *
 * Renders into an ordinary memory buffer with OSMesa and checks the pixels:
 *   1. clear colour and a flat triangle
 *   2. a lit GLU sphere (exercises libGLU7, lighting and the sin/cos paths)
 *   3. depth testing (a near and a far quad)
 * Writes osmesa_test.ppm and returns 0 when every check passes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/osmesa.h>

#define W 160
#define H 120

static int failures = 0;

static void check(const char *what, int ok)
{
    printf("  %-44s %s\n", what, ok ? "PASS" : "FAIL");
    if (!ok) failures++;
}

/* pixel (x, y) with y counted from the TOP of the image (OSMESA_Y_UP = 0) */
static unsigned char *px(unsigned char *buf, int x, int y)
{
    return buf + ((size_t)y * W + x) * 4;
}

static int near_color(const unsigned char *p, int r, int g, int b)
{
    return abs(p[0] - r) < 4 && abs(p[1] - g) < 4 && abs(p[2] - b) < 4;
}

int main(void)
{
    OSMesaContext ctx;
    unsigned char *buf;
    GLint w = 0, h = 0, fmt = 0;
    FILE *f;
    int i;

    printf("OSMesa smoke test (%dx%d, RGBA, 8 bit)\n", W, H);

    buf = (unsigned char *)calloc((size_t)W * H, 4);
    ctx = OSMesaCreateContextExt(OSMESA_RGBA, 16, 0, 0, NULL);
    if (!ctx || !buf) { printf("cannot create context\n"); return 2; }
    if (!OSMesaMakeCurrent(ctx, buf, GL_UNSIGNED_BYTE, W, H)) {
        printf("OSMesaMakeCurrent failed\n");
        return 2;
    }
    OSMesaPixelStore(OSMESA_Y_UP, 0);                 /* row 0 = top */
    OSMesaGetIntegerv(OSMESA_WIDTH, &w);
    OSMesaGetIntegerv(OSMESA_HEIGHT, &h);
    OSMesaGetIntegerv(OSMESA_FORMAT, &fmt);
    check("context reports size and format", w == W && h == H && fmt == OSMESA_RGBA);
    printf("  GL_VERSION  = %s\n  GL_RENDERER = %s\n",
           (const char *)glGetString(GL_VERSION), (const char *)glGetString(GL_RENDERER));

    /* ---- 1. clear + flat triangle ---- */
    glViewport(0, 0, W, H);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.8f, -0.8f); glVertex2f(0.8f, -0.8f); glVertex2f(0.0f, 0.8f);
    glEnd();
    glFinish();
    check("background is blue", near_color(px(buf, 2, 2), 0, 0, 255));
    check("triangle centre is red", near_color(px(buf, W / 2, H / 2 + 10), 255, 0, 0));

    /* ---- 2. lit sphere ---- */
    {
        GLUquadric *q = gluNewQuadric();
        GLfloat pos[4] = { 0.0f, 0.0f, 1.0f, 0.0f };
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING); glEnable(GL_LIGHT0);
        glEnable(GL_COLOR_MATERIAL);
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glMatrixMode(GL_PROJECTION); glLoadIdentity();
        gluPerspective(40.0, (double)W / H, 1.0, 20.0);
        glMatrixMode(GL_MODELVIEW); glLoadIdentity();
        glTranslatef(0, 0, -4);
        glColor3f(0.0f, 1.0f, 0.0f);
        gluSphere(q, 1.2, 24, 16);
        gluDeleteQuadric(q);
        glFinish();
        {
            unsigned char *c = px(buf, W / 2, H / 2);
            unsigned char *e = px(buf, 2, 2);
            check("lit sphere: centre is green and bright", c[1] > 150 && c[0] < 30 && c[2] < 30);
            check("lit sphere: corner stays black", e[0] == 0 && e[1] == 0 && e[2] == 0);
        }
        glDisable(GL_LIGHTING);
    }

    /* ---- 3. depth test: far red quad drawn after a near blue one ---- */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glOrtho(-1, 1, -1, 1, 0.0, 10.0);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);                       /* near (z = -1) */
    glVertex3f(-0.5f, -0.5f, -1); glVertex3f(0.5f, -0.5f, -1);
    glVertex3f(0.5f, 0.5f, -1);   glVertex3f(-0.5f, 0.5f, -1);
    glEnd();
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);                       /* far (z = -5), drawn second */
    glVertex3f(-0.9f, -0.9f, -5); glVertex3f(0.9f, -0.9f, -5);
    glVertex3f(0.9f, 0.9f, -5);   glVertex3f(-0.9f, 0.9f, -5);
    glEnd();
    glFinish();
    check("near quad hides far quad (depth buffer)", near_color(px(buf, W / 2, H / 2), 0, 0, 255));
    check("far quad visible around it", near_color(px(buf, W / 2 + 60, H / 2), 255, 0, 0));

    /* ---- image dump ---- */
    f = fopen("osmesa_test.ppm", "wb");
    if (f) {
        fprintf(f, "P6\n%d %d\n255\n", W, H);
        for (i = 0; i < W * H; i++) fwrite(buf + i * 4, 1, 3, f);
        fclose(f);
        printf("  wrote osmesa_test.ppm\n");
    }

    OSMesaDestroyContext(ctx);
    free(buf);
    printf("%s\n", failures ? "FAILED" : "ALL TESTS PASSED");
    return failures ? 1 : 0;
}
