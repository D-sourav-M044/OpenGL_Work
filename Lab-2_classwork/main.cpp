#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

const int width = 700;
const int height = 700;

GLfloat eyeX = 0;
GLfloat eyeY = 5;
GLfloat eyeZ = 20;

GLfloat lookX = 0;
GLfloat lookY = 0;
GLfloat lookZ = 0;

float rot = 0;


static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
    {0,2,6,4},
    {1,3,7,5},
    {0,4,5,1},
    {2,6,7,3},
    {0,1,3,2},
    {4,5,7,6}
};


void cube(float colR=0.5, float colG=0.5, float colB=0.5, float alpha=1)
{
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        //glColor4f(colR,colG,colB,alpha);
        glColor3f(colR,colG,colB);

        colR += 0.04;
        colG += 0.04;
        colB += 0.04;

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}

void axes()
{
    float length = 10;
    float width = 0.3;

    // X-axis
    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,width,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,0,0); //RED Line
    glPopMatrix();

    // Y-axis
    glPushMatrix();
    glTranslatef(0,length/2,0);
    glScalef(width,length,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0,1,0); //GREEN Line
    glPopMatrix();

    // Z-axis
    glPushMatrix();
    glTranslatef(0,0,length/2);
    glScalef(width,width,length);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0,0,1); //BLUE Line
    glPopMatrix();
}

void flr()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(20,1,20);
    glTranslatef(-0.5,-1,-0.5);
    cube();
    glPopMatrix();
}

void tea_table()
{
    float height=6;
    float width=10;
    float length=5;

    float base_height=1;
    float leg_height=height-base_height;
    float leg_width=0.5;

    // whole table
    glPushMatrix();
    glTranslatef(0,leg_height,0);

    // base
    glPushMatrix();
    glScalef(width,base_height,length);
    glTranslatef(-0.5,0,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    // legs
    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPopMatrix();
}

void table()
{
    float top_length = 20;
    float top_width = 10;
    float top_height = 0.3;

    //table-top
    glPushMatrix();
    glTranslatef(0,top_length/2,0);
    glScalef(top_length,top_height,top_width);
    glTranslatef(-0.5,0.0,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    //side bar
    glPushMatrix();
    glTranslatef(-(top_length/2-3*top_height/2),0,0);
    glScalef(top_height,top_length,top_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((top_length/2-3*top_height/2),0,0);
    glScalef(top_height,top_length,top_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((top_length/2-6.1),0,0);
    glScalef(top_height,top_length,top_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    //middle bar
    glPushMatrix();
    glTranslatef(7-top_height,0,0);
    glScalef(6,top_height,top_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7-top_height,-(top_length/2-4),0);
    glScalef(6,top_height,top_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,(top_length/2-4),0);
    glScalef((top_length-6.6),top_height,top_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    //back bar
    glPushMatrix();
    glTranslatef(-3,(top_length/2-6),-top_width/2);
    glScalef((top_length-6.6),top_width,top_height);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();


}
void chair()
{
    float seat_length =12, seat_height =1, seat_width  =8;

    float leg_length  = 0.8, leg_height  = 12, leg_width  = 0.8;

    //seat
    glPushMatrix();
    glScalef(seat_length,seat_height,seat_width);
    glTranslatef(-0.5,0,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    //upper-leg(left)
    glPushMatrix();
    glTranslatef(-(seat_length/2-leg_length/2),0,-(seat_width/2-leg_width/2));
    glScalef(leg_length,leg_height,leg_width);
    glTranslatef(-0.5,0,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //upper-leg(right)
    glPushMatrix();
    glTranslatef((seat_length/2-leg_length/2),0,-(seat_width/2-leg_width/2));
    glScalef(leg_length,leg_height,leg_width);
    glTranslatef(-0.5,0,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //lower-leg(left)-Rear
    glPushMatrix();
    glTranslatef(-(seat_length/2-leg_length/2),0,-(seat_width/2-leg_width/2));
    glScalef(leg_length,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //lower-leg(left)-Front
    glPushMatrix();
    glTranslatef(-(seat_length/2-leg_length/2),0,(seat_width/2-leg_width/2));
    glScalef(leg_length,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //lower-leg(right)-Rear
    glPushMatrix();
    glTranslatef((seat_length/2-leg_length/2),0,-(seat_width/2-leg_width/2));
    glScalef(leg_length,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //lower-leg(right)-Front
    glPushMatrix();
    glTranslatef((seat_length/2-leg_length/2),0,(seat_width/2-leg_width/2));
    glScalef(leg_length,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //Rail-upper
    glPushMatrix();
    glTranslatef(0,6,-(seat_width/2-leg_width/2));
    glScalef(seat_length,seat_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //Rail-upper
    glPushMatrix();
    glTranslatef(0,8,-(seat_width/2-leg_width/2));
    glScalef(seat_length,seat_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //Rail-upper
    glPushMatrix();
    glTranslatef(0,10,-(seat_width/2-leg_width/2));
    glScalef(seat_length,seat_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //Rail-upper
    glPushMatrix();
    glTranslatef(0,12,-(seat_width/2-leg_width/2));
    glScalef(seat_length,seat_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //Rail-lower
    glPushMatrix();
    glTranslatef(0,-8,-(seat_width/2-leg_width/2));
    glScalef(seat_length,seat_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //Rail-lower
    glPushMatrix();
    glTranslatef(0,-8,(seat_width/2-leg_width/2));
    glScalef(seat_length,seat_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //Rail-lower
    glPushMatrix();
    glTranslatef((seat_length/2-leg_width/2),-8,0);
    glScalef(leg_width,leg_width,seat_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //Rail-lower
    glPushMatrix();
    glTranslatef(-(seat_length/2-leg_width/2),-8,0);
    glScalef(leg_width,leg_width,seat_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

}

void almirah()
{
    float length = 5, width = 5, height =10;
    glPushMatrix();
    //glTranslatef(0,top_length/2,0);
    glScalef(length,height,width);
    glTranslatef(-0.5,0,-0.5);
    cube(0.235, 0.702, 0.443);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,width/2);
    glScalef(0.3,height,0.5);
    glTranslatef(-0.5,0,-0.5);
    //cube(0.53,0.55,0.28);
    cube(0.663, 0.663, 0.663);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3,height/2,width/2);
    glScalef(0.3,1,0.5);
    glTranslatef(-0.5,0,-0.5);
    //cube(0.53,0.55,0.28);
    cube(1,1, 1.000);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3,height/2,width/2);
    glScalef(0.3,1,0.5);
    glTranslatef(-0.5,0,-0.5);
    //cube(0.53,0.55,0.28);
    cube(0.973, 0.973, 1.000);
    glPopMatrix();
}

void shelf()
{
    float top_length = 8;
    float top_width = 10;
    float top_height = 0.3;

    glPushMatrix();
    glTranslatef(0,top_width-(6*top_height),0);
    glScalef(12*top_height,8*top_height,3*top_height);
    glTranslatef(-0.5,0.0,-0.5);
    cube(0.824, 0.412, 0.118);
    glPopMatrix();

    //table-top
    glPushMatrix();
    glTranslatef(0,top_length,0);
    glScalef(top_length,top_height,top_width);
    glTranslatef(-0.5,0.0,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    //side bar
    for(int i=-1;i<=1;i=i+2)
    {
        glPushMatrix();
    glTranslatef((i)*(top_length/2-top_height/2),0,0);
    glScalef(top_height,top_length,top_width);
    glTranslatef(-0.5,-0.0,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();
    }
    //books

    for (int i=0;i<=1;i++)
    {int sp = 1,m=0;

        for(int j=1;j<6;j++)
        {sp+=1;
            glPushMatrix();
    glTranslatef(-(top_length/2-sp-top_height),top_length/2+(1.5-5*i),0);
    glRotatef(30,0,0,1);
    glScalef(2*top_height,9*top_height,5*top_height);
    glTranslatef(-0.5,-0.0,-0.5);
    cube(0.480+m+ 0.09*2*j, 0.502+m+0.05*2*j, 0.447+m+0.05*2*j);
    glPopMatrix();

        }
        m+=0.8;

    }

    //shelf bar
    for(int i=0;i<=1;i++)
    {
        glPushMatrix();
    glTranslatef((top_length/2-top_length/2),(top_length/2+1)*i,0);
    glScalef(top_length,top_height,top_width);
    glTranslatef(-0.5,-0.0,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();
    }

   //back bar
    glPushMatrix();
    glTranslatef(0,0,-top_width/2);
    glScalef(top_length,top_length,top_height);
    glTranslatef(-0.5,0.0,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

}


void fan()
{

}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5, 5, -5, 5, 4, 50);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, width, height);

    glRotatef(rot, 0,1,0);
    axes();

//    glPushMatrix();
//    glRotatef(180,0,1,0);
//    glScalef(0.75,0.75,0.75);
//    chair();
//    glPopMatrix();
//
//    glPushMatrix();
//    glTranslatef(0,-5.5,-8);
//    glScalef(2,2,1);
//    tea_table();
//    glPopMatrix();
    shelf();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;

    case 'w':
        eyeY++;
        break;
    case 's':
        eyeY--;
        break;
    case 'a':
        rot--;
        break;
    case 'd':
        rot++;
        break;
    case '+':
        eyeZ--;
        break;
    case '-':
        eyeZ++;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    // glutIdleFunc(idle);

//    glClearColor(1,1,1,1);

    glEnable(GL_DEPTH_TEST);
    glShadeModel( GL_SMOOTH );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);

    printf("########################################################################################\n");
    printf("########################################################################################\n");
    printf("##############                                                         #################\n");
    printf("##############           PLEASE FOLLOW THE BELOW INSTRUCTIONS          #################\n");
    printf("##############                                                         #################\n");
    printf("########################################################################################\n");
    printf("########################################################################################\n\n\n");
    printf("Use 'w' to look up, 's' to look down, 'd' to look right, and 'a' to look left.\n");
    printf("Use 'i' to move camera up, 'k' to move camera down, 'l' to move camera right, and 'j' to move camera left with the look at point fixed.\n");
    printf("Use '+' to zoom in and '-' to zoom out.\n\n\n");

    glutMainLoop();

    return EXIT_SUCCESS;
}
