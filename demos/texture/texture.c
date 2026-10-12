/* texture.c -- textured, blended spinning cube.  Exercises texture mapping,
 * mipmaps via gluBuild2DMipmaps (libGLU7), alpha blending and GL state.
 * Keys: f filter (nearest/linear/mipmap), b blend, space pause, ESC quits. */
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define TEXSZ 64
static GLubyte tex[TEXSZ][TEXSZ][4];
static GLuint texId;
static int filter = 2, blend = 0, paused = 0;
static float ax = 20.0f, ay = 0.0f;

static void makeTexture(void)
{
    int i, j;
    for (i = 0; i < TEXSZ; i++)
        for (j = 0; j < TEXSZ; j++) {
            int c = (((i >> 3) & 1) ^ ((j >> 3) & 1));
            tex[i][j][0] = c ? 240 : (GLubyte)(40 + i * 2);
            tex[i][j][1] = c ? 240 : (GLubyte)(60 + j * 2);
            tex[i][j][2] = c ? 80  : 160;
            tex[i][j][3] = 200;
        }
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, TEXSZ, TEXSZ, GL_RGBA,
                      GL_UNSIGNED_BYTE, tex);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

static void applyFilter(void)
{
    GLint mag = filter == 0 ? GL_NEAREST : GL_LINEAR;
    GLint min = filter == 0 ? GL_NEAREST : filter == 1 ? GL_LINEAR
                                                       : GL_LINEAR_MIPMAP_LINEAR;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min);
}

/* one quad on the +Z side; the caller rotates it into place */
static void face(void)
{
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, 1);
    glTexCoord2f(2, 0); glVertex3f( 1, -1, 1);
    glTexCoord2f(2, 2); glVertex3f( 1,  1, 1);
    glTexCoord2f(0, 2); glVertex3f(-1,  1, 1);
    glEnd();
}

static void display(void)
{
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(ax, 1, 0, 0);
    glRotatef(ay, 0, 1, 0);

    if (blend) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDepthMask(GL_FALSE);
    } else {
        glDisable(GL_BLEND);
        glDepthMask(GL_TRUE);
    }
    applyFilter();

    glColor4f(1, 1, 1, 0.6f);
    face();
    glPushMatrix(); glRotatef(90, 0, 1, 0);   face(); glPopMatrix();
    glPushMatrix(); glRotatef(180, 0, 1, 0);  face(); glPopMatrix();
    glPushMatrix(); glRotatef(270, 0, 1, 0);  face(); glPopMatrix();
    glPushMatrix(); glRotatef(90, 1, 0, 0);   face(); glPopMatrix();
    glPushMatrix(); glRotatef(-90, 1, 0, 0);  face(); glPopMatrix();

    glutSwapBuffers();
}

static void timer(int v)
{
    (void)v;
    if (!paused) { ay += 1.2f; ax += 0.4f; }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

static void reshape(int w, int h)
{
    if (h < 1) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

static void key(unsigned char k, int x, int y)
{
    (void)x; (void)y;
    if (k == 'f') filter = (filter + 1) % 3;
    else if (k == 'b') blend = !blend;
    else if (k == ' ') paused = !paused;
    else if (k == 27) exit(0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Mesa Texture - ArcaOS");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    makeTexture();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutTimerFunc(16, timer, 0);
    glutMainLoop();
    return 0;
}
