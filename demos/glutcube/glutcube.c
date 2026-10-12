/*
 * glutcube.c -- rotating cube, Mesa 7.11.2 / ArcaOS GLUT demo
 *
 * Build:  see compile_glutcube.cmd
 * Run:    glutcube.exe
 * Keys:   ESC or 'q' to quit
 */

#include <GL/glut.h>
#include <stdlib.h>

static float g_angle = 0.0f;

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(g_angle,       1.0f, 0.0f, 0.0f);
    glRotatef(g_angle * 0.7f, 0.0f, 1.0f, 0.0f);
    glRotatef(g_angle * 0.3f, 0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);
        /* front */
        glColor3f(1,0,0);  glVertex3f(-1,-1, 1);
        glColor3f(1,1,0);  glVertex3f( 1,-1, 1);
        glColor3f(0,1,0);  glVertex3f( 1, 1, 1);
        glColor3f(0,0,1);  glVertex3f(-1, 1, 1);
        /* back */
        glColor3f(0,0,1);  glVertex3f(-1,-1,-1);
        glColor3f(0,1,0);  glVertex3f(-1, 1,-1);
        glColor3f(1,1,0);  glVertex3f( 1, 1,-1);
        glColor3f(1,0,0);  glVertex3f( 1,-1,-1);
        /* top */
        glColor3f(0,1,0);  glVertex3f(-1, 1,-1);
        glColor3f(0,1,1);  glVertex3f(-1, 1, 1);
        glColor3f(1,1,1);  glVertex3f( 1, 1, 1);
        glColor3f(1,1,0);  glVertex3f( 1, 1,-1);
        /* bottom */
        glColor3f(1,0,0);  glVertex3f(-1,-1,-1);
        glColor3f(1,0,1);  glVertex3f( 1,-1,-1);
        glColor3f(1,1,0);  glVertex3f( 1,-1, 1);
        glColor3f(0,0,1);  glVertex3f(-1,-1, 1);
        /* right */
        glColor3f(1,0,1);  glVertex3f( 1,-1,-1);
        glColor3f(1,1,0);  glVertex3f( 1, 1,-1);
        glColor3f(1,1,1);  glVertex3f( 1, 1, 1);
        glColor3f(1,0,0);  glVertex3f( 1,-1, 1);
        /* left */
        glColor3f(0,0,1);  glVertex3f(-1,-1,-1);
        glColor3f(0,1,0);  glVertex3f(-1,-1, 1);
        glColor3f(0,1,1);  glVertex3f(-1, 1, 1);
        glColor3f(0,0,0);  glVertex3f(-1, 1,-1);
    glEnd();

    glutSwapBuffers();
}

static void reshape(int w, int h)
{
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 0.5, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void idle(void)
{
    g_angle += 0.5f;
    if (g_angle >= 360.0f) g_angle -= 360.0f;
    glutPostRedisplay();
}

static void keyboard(unsigned char key, int x, int y)
{
    (void)x; (void)y;
    if (key == 27 || key == 'q' || key == 'Q')
        exit(0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mesa GLUT Cube - ArcaOS");

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
