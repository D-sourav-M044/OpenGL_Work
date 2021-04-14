#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<bits/stdc++.h>
using namespace std;


int lt = 0;


void menu()
{
    cout<<"--------------------------CSE-4208-----------------------------"<<endl;
    cout<<"________________________________________________________________"<<endl;
    cout<<" Press 1 for Fist Assignment"<<endl;
    cout<<" Press 2 for Second Assignment"<<endl;
    cout<<" Press 3 for Third Assignment"<<endl;
    cout<<"           Press 0 to Quit"<<endl;
    cout<<"________________________________________________________________"<<endl<<endl;;
    cout<<"\t\t showing first assignment "<<endl;
    cout<<"\t\t ------------------------"<<endl;
    cout<<"\t\t to translate 1.5 units left >>press  l "<<endl<<endl<<endl;

}

void rectangle()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(1.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(1.0,2.0);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(0.0,2.0);
    glEnd();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(-3, 3, -3, 3);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glViewport(0, 0,400,400);

    glPushMatrix();
    glTranslatef(lt,0,0);
    rectangle();
    glPopMatrix();


    glFlush();
    glutSwapBuffers();
}
