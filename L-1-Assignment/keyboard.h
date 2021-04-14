#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<bits/stdc++.h>
using namespace std;

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'r':
        flagScale=true;
        break;
    case 's':
        flagScale=false;
        break;
    case 'l':
        lt-=1.5;
        break;
    case '1':
        menu();
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glShadeModel( GL_SMOOTH );
        glEnable( GL_DEPTH_TEST );
        glutDisplayFunc(display);
        glutKeyboardFunc(myKeyboardFunc);
        glutMainLoop();
        break;
    case '2':
        cout<<"\t\t showing second assignment "<<endl;
        cout<<"\t\t ------------------------"<<endl;
        cout<<"\t\t  to start rotation press  >>press  r "<<endl;
        cout<<"\t\t  to stop rotation press  >>press  s "<<endl;
        cout<<"___________________________________________________________________________________________________________"<<endl<<endl<<endl;
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glShadeModel( GL_SMOOTH );
        glEnable( GL_DEPTH_TEST );
        glutDisplayFunc(display2);
        glutKeyboardFunc(myKeyboardFunc);
        glutIdleFunc(animate);
        glutMainLoop();
        break;
    case '3':
        cout<<"\t\t showing third assignment "<<endl;
        cout<<"___________________________________________________________________________________________________________"<<endl<<endl<<endl;
        colorset();
        glutDisplayFunc(display3);
        glutIdleFunc(animation);
        glutMainLoop();
        break;
    case '0':
        exit(1);

    }
    glutPostRedisplay();
}
