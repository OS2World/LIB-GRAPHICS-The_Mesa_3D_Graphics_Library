/* gears.c -- classic three-gear demo for Mesa/OS2 (lighting, display lists,
 * double buffering, idle-driven animation, arrow-key view control).
 * Keys: arrows rotate the view, z/Z spin, ESC quits.
 *
 * Build note: compile with -fno-builtin-sinf -fno-builtin-cosf (see
 * build_demos.cmd).  At -O2 GCC otherwise merges the sinf(a)/cosf(a) pairs
 * below into one call to cexpf(), and this platform's libm returns NaN
 * for it, which makes every gear vertex NaN (an all-black window). */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

static GLint gear1, gear2, gear3;
static GLfloat viewRotX = 20.0f, viewRotY = 30.0f, viewRotZ = 0.0f;
static GLfloat angle = 0.0f;
static int frames = 0, t0 = 0;

static void gear(GLfloat inner, GLfloat outer, GLfloat width, GLint teeth,
                 GLfloat toothDepth)
{
    GLint i;
    GLfloat r0 = inner, r1 = outer - toothDepth / 2.0f,
            r2 = outer + toothDepth / 2.0f;
    GLfloat da = 2.0f * (GLfloat)M_PI / teeth / 4.0f;
    GLfloat u, v, len, a;

    glShadeModel(GL_FLAT);
    glNormal3f(0.0f, 0.0f, 1.0f);

    /* front face */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= teeth; i++) {
        a = i * 2.0f * (GLfloat)M_PI / teeth;
        glVertex3f(r0 * cosf(a), r0 * sinf(a), width * 0.5f);
        glVertex3f(r1 * cosf(a), r1 * sinf(a), width * 0.5f);
        if (i < teeth) {
            glVertex3f(r0 * cosf(a), r0 * sinf(a), width * 0.5f);
            glVertex3f(r1 * cosf(a + 3 * da), r1 * sinf(a + 3 * da), width * 0.5f);
        }
    }
    glEnd();

    /* front sides of teeth */
    glBegin(GL_QUADS);
    for (i = 0; i < teeth; i++) {
        a = i * 2.0f * (GLfloat)M_PI / teeth;
        glVertex3f(r1 * cosf(a), r1 * sinf(a), width * 0.5f);
        glVertex3f(r2 * cosf(a + da), r2 * sinf(a + da), width * 0.5f);
        glVertex3f(r2 * cosf(a + 2 * da), r2 * sinf(a + 2 * da), width * 0.5f);
        glVertex3f(r1 * cosf(a + 3 * da), r1 * sinf(a + 3 * da), width * 0.5f);
    }
    glEnd();

    glNormal3f(0.0f, 0.0f, -1.0f);

    /* back face */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= teeth; i++) {
        a = i * 2.0f * (GLfloat)M_PI / teeth;
        glVertex3f(r1 * cosf(a), r1 * sinf(a), -width * 0.5f);
        glVertex3f(r0 * cosf(a), r0 * sinf(a), -width * 0.5f);
        if (i < teeth) {
            glVertex3f(r1 * cosf(a + 3 * da), r1 * sinf(a + 3 * da), -width * 0.5f);
            glVertex3f(r0 * cosf(a), r0 * sinf(a), -width * 0.5f);
        }
    }
    glEnd();

    /* back sides of teeth */
    glBegin(GL_QUADS);
    for (i = 0; i < teeth; i++) {
        a = i * 2.0f * (GLfloat)M_PI / teeth;
        glVertex3f(r1 * cosf(a + 3 * da), r1 * sinf(a + 3 * da), -width * 0.5f);
        glVertex3f(r2 * cosf(a + 2 * da), r2 * sinf(a + 2 * da), -width * 0.5f);
        glVertex3f(r2 * cosf(a + da), r2 * sinf(a + da), -width * 0.5f);
        glVertex3f(r1 * cosf(a), r1 * sinf(a), -width * 0.5f);
    }
    glEnd();

    /* outward faces of teeth */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i < teeth; i++) {
        a = i * 2.0f * (GLfloat)M_PI / teeth;
        glVertex3f(r1 * cosf(a), r1 * sinf(a), width * 0.5f);
        glVertex3f(r1 * cosf(a), r1 * sinf(a), -width * 0.5f);
        u = r2 * cosf(a + da) - r1 * cosf(a);
        v = r2 * sinf(a + da) - r1 * sinf(a);
        len = sqrtf(u * u + v * v);
        u /= len; v /= len;
        glNormal3f(v, -u, 0.0f);
        glVertex3f(r2 * cosf(a + da), r2 * sinf(a + da), width * 0.5f);
        glVertex3f(r2 * cosf(a + da), r2 * sinf(a + da), -width * 0.5f);
        glNormal3f(cosf(a), sinf(a), 0.0f);
        glVertex3f(r2 * cosf(a + 2 * da), r2 * sinf(a + 2 * da), width * 0.5f);
        glVertex3f(r2 * cosf(a + 2 * da), r2 * sinf(a + 2 * da), -width * 0.5f);
        u = r1 * cosf(a + 3 * da) - r2 * cosf(a + 2 * da);
        v = r1 * sinf(a + 3 * da) - r2 * sinf(a + 2 * da);
        glNormal3f(v, -u, 0.0f);
        glVertex3f(r1 * cosf(a + 3 * da), r1 * sinf(a + 3 * da), width * 0.5f);
        glVertex3f(r1 * cosf(a + 3 * da), r1 * sinf(a + 3 * da), -width * 0.5f);
        glNormal3f(cosf(a), sinf(a), 0.0f);
    }
    glVertex3f(r1 * cosf(0.0f), r1 * sinf(0.0f), width * 0.5f);
    glVertex3f(r1 * cosf(0.0f), r1 * sinf(0.0f), -width * 0.5f);
    glEnd();

    glShadeModel(GL_SMOOTH);

    /* inside radius cylinder */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= teeth; i++) {
        a = i * 2.0f * (GLfloat)M_PI / teeth;
        glNormal3f(-cosf(a), -sinf(a), 0.0f);
        glVertex3f(r0 * cosf(a), r0 * sinf(a), -width * 0.5f);
        glVertex3f(r0 * cosf(a), r0 * sinf(a), width * 0.5f);
    }
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(viewRotX, 1.0f, 0.0f, 0.0f);
    glRotatef(viewRotY, 0.0f, 1.0f, 0.0f);
    glRotatef(viewRotZ, 0.0f, 0.0f, 1.0f);

    glPushMatrix();
    glTranslatef(-3.0f, -2.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glCallList(gear1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.1f, -2.0f, 0.0f);
    glRotatef(-2.0f * angle - 9.0f, 0.0f, 0.0f, 1.0f);
    glCallList(gear2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.1f, 4.2f, 0.0f);
    glRotatef(-2.0f * angle - 25.0f, 0.0f, 0.0f, 1.0f);
    glCallList(gear3);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();

    frames++;
    {
        int t = glutGet(GLUT_ELAPSED_TIME);
        if (t - t0 >= 5000) {
            fprintf(stderr, "gears: %d frames in %.1f s = %.1f FPS\n", frames,
                    (t - t0) / 1000.0, frames * 1000.0 / (t - t0));
            t0 = t;
            frames = 0;
        }
    }
}

static void idle(void)
{
    angle += 1.5f;
    glutPostRedisplay();
}

static void reshape(int w, int h)
{
    GLfloat ratio;
    if (h < 1) h = 1;
    ratio = (GLfloat)h / (GLfloat)w;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -ratio, ratio, 5.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -40.0f);
}

static void special(int k, int x, int y)
{
    (void)x; (void)y;
    switch (k) {
    case GLUT_KEY_UP:    viewRotX += 5.0f; break;
    case GLUT_KEY_DOWN:  viewRotX -= 5.0f; break;
    case GLUT_KEY_LEFT:  viewRotY += 5.0f; break;
    case GLUT_KEY_RIGHT: viewRotY -= 5.0f; break;
    }
    glutPostRedisplay();
}

static void key(unsigned char k, int x, int y)
{
    (void)x; (void)y;
    switch (k) {
    case 'z': viewRotZ += 5.0f; break;
    case 'Z': viewRotZ -= 5.0f; break;
    case 27:  exit(0);
    }
    glutPostRedisplay();
}

static void init(void)
{
    static GLfloat pos[4]   = { 5.0f, 5.0f, 10.0f, 0.0f };
    static GLfloat red[4]   = { 0.8f, 0.1f, 0.0f, 1.0f };
    static GLfloat green[4] = { 0.0f, 0.8f, 0.2f, 1.0f };
    static GLfloat blue[4]  = { 0.2f, 0.2f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    gear1 = glGenLists(1);
    glNewList(gear1, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
    gear(1.0f, 4.0f, 1.0f, 20, 0.7f);
    glEndList();

    gear2 = glGenLists(1);
    glNewList(gear2, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, green);
    gear(0.5f, 2.0f, 2.0f, 10, 0.7f);
    glEndList();

    gear3 = glGenLists(1);
    glNewList(gear3, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    gear(1.3f, 2.0f, 0.5f, 10, 0.7f);
    glEndList();

    glEnable(GL_NORMALIZE);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Mesa Gears - ArcaOS");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);
    glutIdleFunc(idle);
    t0 = glutGet(GLUT_ELAPSED_TIME);
    glutMainLoop();
    return 0;
}
