#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<bits/stdc++.h>
using namespace std;

GLfloat t= 0;

void colorset()
{
    glClearColor(0,0,0,1);
    glColor3f(1,1,0);
    glEnable(GL_DEPTH_TEST);
}
void side(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[])
{
    glBegin(GL_QUADS);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);
    glEnd();
}
void cube(GLfloat v0[],GLfloat v1[],GLfloat v2[],GLfloat v3[],GLfloat v4[],GLfloat v5[],GLfloat v6[],GLfloat v7[])
{
    glColor3f(1,0.5,0.5);
    side(v0,v1,v2,v3);//front

    glColor3f(0.5,1,0.2);
    side(v4,v5,v6,v7);//back

    glColor3f(0.3,0,0.8);
    side(v0,v3,v7,v4);//left

    glColor3f(0.8,0.5,0.2);
    side(v1,v2,v6,v5);//right


    glColor3f(0.2,0,0.5);
    side(v0,v1,v5,v4);//top

    glColor3f(1,0.5,0.6);
    side(v3,v2,v6,v7);//right



}

void display3()
{

    GLfloat v[8][3] =
    {
        {-0.4,0.4,0.4},
        {0.4,0.4,0.4},
        {0.4,-0.4,0.4},
        {-0.4,-0.4,0.4},

        {-0.4,0.4,-0.4},
        {0.4,0.4,-0.4},
        {0.4,-0.4,-0.4},
        {-0.4,-0.4,-0.4},
    };
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(t,0,1,1);
    cube(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7]);
    glMatrixMode( GL_PROJECTION );

    glutSwapBuffers();


}
void animation()
{
    t = t+0.85;
    if(t>360)
        t =0;
    glutPostRedisplay();
}
