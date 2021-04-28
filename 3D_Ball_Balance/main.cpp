#include "header.h"

const int window_width = 1200;
const int window_height = 750;

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int lim = 8;
    glFrustum(-lim, lim, -lim, lim, 4, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    gluLookAt(eye[0],eye[1],eye[2], look[0],look[1],look[2], 0,1,0);

    glRotatef(m_rot,0,1,0);
    extra_light();
    axes();
    glPushMatrix();
    glRotatef(ball_rot,0,0,1);
    ball();
    glPopMatrix();
    glPushMatrix();
    floor();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(window_width,window_height);
    glutInitWindowPosition(300,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    //extra_light();
    glutCreateWindow("3D Ball Balance");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);



    glEnable(GL_DEPTH_TEST);
    glShadeModel( GL_SMOOTH );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);
    glEnable(GL_LIGHTING);



    glutMainLoop();



    return EXIT_SUCCESS;
}
