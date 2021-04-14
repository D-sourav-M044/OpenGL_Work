#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<bits/stdc++.h>
using namespace std;

bool flagScale;
int rot = 0;

void display2()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-3, 3, -3, 3);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glViewport(0, 0,500,500);

    glPushMatrix();
    glRotatef(rot,0,0,1);
    rectangle();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}
void animate()
{
    if (flagScale == true)
    {
        rot+= 5;
    }
    glutPostRedisplay();
}
