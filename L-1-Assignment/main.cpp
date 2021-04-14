#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<bits/stdc++.h>
using namespace std;

#include "one.h"
#include "two.h"
#include "three.h"
#include "keyboard.h"


int main (int argc, char **argv)
{
    menu();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(910,100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lab-1 Assignment");
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboardFunc);
    glutMainLoop();
}
