/* shapes.c -- GLUT solid/wire shapes with lighting, mouse-drag rotation,
 * timer-driven animation and a bitmap-font overlay.
 * Keys: 1..8 pick a shape, w wire/solid, l lighting, space pause, ESC quits.
 * Left mouse drag rotates; up/down arrows change the spin speed. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

static const char *names[] = {
    "Teapot", "Sphere", "Torus", "Cone", "Cube", "Dodecahedron",
    "Icosahedron", "Octahedron"
};
static int shape = 0, wire = 0, lighting = 1, paused = 0;
static float rotX = 25.0f, rotY = 0.0f, spin = 1.0f;
static int dragging = 0, lastX, lastY;
static int winW = 400, winH = 400;
static int frames = 0, t0 = 0, fps = 0;

static void text(float x, float y, const char *s)
{
    glRasterPos2f(x, y);
    while (*s) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *s++);
}

static void drawShape(void)
{
    switch (shape) {
    case 0: if (wire) glutWireTeapot(1.0);         else glutSolidTeapot(1.0); break;
    case 1: if (wire) glutWireSphere(1.2, 24, 16); else glutSolidSphere(1.2, 24, 16); break;
    case 2: if (wire) glutWireTorus(0.4, 1.0, 16, 32); else glutSolidTorus(0.4, 1.0, 16, 32); break;
    case 3: if (wire) glutWireCone(1.0, 2.0, 24, 8); else glutSolidCone(1.0, 2.0, 24, 8); break;
    case 4: if (wire) glutWireCube(1.6);           else glutSolidCube(1.6); break;
    case 5: if (wire) glutWireDodecahedron();      else glutSolidDodecahedron(); break;
    case 6: if (wire) glutWireIcosahedron();       else glutSolidIcosahedron(); break;
    default: if (wire) glutWireOctahedron();       else glutSolidOctahedron(); break;
    }
}

static void display(void)
{
    char buf[96];
    glClearColor(0.08f, 0.09f, 0.14f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (double)winW / winH, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -6.0f);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);

    if (lighting) glEnable(GL_LIGHTING); else glDisable(GL_LIGHTING);
    glColor3f(0.9f, 0.55f, 0.2f);
    drawShape();

    /* 2D overlay */
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, winW, 0, winH, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.9f, 0.9f, 0.9f);
    sprintf(buf, "%s (%s)  %d fps", names[shape], wire ? "wire" : "solid", fps);
    text(8, (float)winH - 18, buf);
    text(8, 8, "1-8 shape  w wire  l light  space pause  drag rotate  ESC quit");
    glEnable(GL_DEPTH_TEST);

    glutSwapBuffers();

    frames++;
    {
        int t = glutGet(GLUT_ELAPSED_TIME);
        if (t - t0 >= 1000) { fps = frames * 1000 / (t - t0); frames = 0; t0 = t; }
    }
}

static void timer(int v)
{
    (void)v;
    if (!paused) rotY += spin;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

static void reshape(int w, int h)
{
    winW = w; winH = h < 1 ? 1 : h;
    glViewport(0, 0, winW, winH);
}

static void key(unsigned char k, int x, int y)
{
    (void)x; (void)y;
    if (k >= '1' && k <= '8') shape = k - '1';
    else if (k == 'w') wire = !wire;
    else if (k == 'l') lighting = !lighting;
    else if (k == ' ') paused = !paused;
    else if (k == 27) exit(0);
    glutPostRedisplay();
}

static void special(int k, int x, int y)
{
    (void)x; (void)y;
    if (k == GLUT_KEY_UP)   spin += 0.5f;
    if (k == GLUT_KEY_DOWN) spin -= 0.5f;
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        dragging = (state == GLUT_DOWN);
        lastX = x; lastY = y;
    }
}

static void motion(int x, int y)
{
    if (!dragging) return;
    rotY += (x - lastX) * 0.5f;
    rotX += (y - lastY) * 0.5f;
    lastX = x; lastY = y;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    static GLfloat pos[4] = { 3.0f, 4.0f, 5.0f, 0.0f };
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(winW, winH);
    glutCreateWindow("Mesa Shapes - ArcaOS");

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutTimerFunc(16, timer, 0);
    t0 = glutGet(GLUT_ELAPSED_TIME);
    glutMainLoop();
    return 0;
}
