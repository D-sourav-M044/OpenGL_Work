#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

const int window_width = 1080;
const int window_height = 720;

GLfloat eyeX = 0;
GLfloat eyeY = 20;
GLfloat eyeZ = 40;

GLfloat lookX = 0;
GLfloat lookY = 15;
GLfloat lookZ = -20;

float rot = 0, fan_rt = 0;


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

void fan_rotation()
{
    fan_rt = fan_rt+1;
    if(fan_rt>360)
        fan_rt =0;
    glutPostRedisplay();
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



void desk()
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
    for(int i=-1; i<=1; i=i+2)
    {
        glPushMatrix();
        glTranslatef((i)*(top_length/2-top_height/2),0,0);
        glScalef(top_height,top_length,top_width);
        glTranslatef(-0.5,-0.0,-0.5);
        cube(0.53,0.39,0.28);
        glPopMatrix();
    }
    //books

    for (int i=0; i<=1; i++)
    {
        int sp = 1,m=0;

        for(int j=1; j<6; j++)
        {
            sp+=1;
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
    for(int i=0; i<=1; i++)
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
    float base = 5;

    glPushMatrix();
    glRotatef(fan_rt,0,1,0);

    //fan-cap
    int cap_rot = 0;
    for(int i=0; i<100; i++)
    {
        glPushMatrix();
        glTranslatef(0,base/4,0);
        glRotatef(cap_rot,0,1,0);
        glScalef(base/4,base*2,base/4);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.941, 0.902, 0.549);
        glPopMatrix();
        cap_rot+=5;
    }

    //round-base
    int base_rot = 0;
    for (int i=0; i<100; i++)
    {
        glPushMatrix();
        //glTranslatef(0,top_width-(6*top_height),0);
        glRotatef(base_rot,0,1,0);
        glScalef(base,base/4,base);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.804, 0.361, 0.361);
        glPopMatrix();
        base_rot+=5;
    }
    //fan-leg
    for(int i=0; i<=2; i++)
    {
        glPushMatrix();
        glRotatef(120*i,0,1,0);
        glTranslatef((2*base)/2+base/2,base/8,0);
        glScalef(2*base,0.002*base,base/2);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.000, 0.000, 0.545);
        glPopMatrix();
    }

    fan_rotation();
    glPopMatrix();

}


void ac()
{
    float ac_length = 15, ac_width = 10, ac_height = 5;
        glPushMatrix();
        glScalef(ac_length,ac_height,ac_width);
        glTranslatef(-0.5,0.0,-0.5);
        cube(1.000, 1.000, 0.878);
        glPopMatrix();

        //black line
        for(float i=0.5;i<=1.5;i+=0.5)
        {
        glPushMatrix();
        glTranslatef(0,3.0+i,ac_height-0.8);
        glScalef(ac_length-8,ac_height/20,ac_width/5);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0, 0, 0);
        glPopMatrix();
        }



        glPushMatrix();
        glTranslatef(0,0.5,ac_height-0.8);
        glScalef(ac_length,ac_height/4,ac_width/5);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.663, 0.663, 0.663);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,1,ac_height-0.5);
        glScalef(ac_length,ac_height/12,ac_width/5);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.000, 0.000, 0.000);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(ac_length/2-ac_length/16,2,ac_height-0.5);
        glScalef(ac_length/8,ac_height/12,ac_width/5);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.502, 0.000, 0.000);
        glPopMatrix();

        //back part
        for(int i=-1;i<=1;i+=1)
        {
        glPushMatrix();
        glTranslatef((i)*(ac_length/2-ac_length/10),2,-(ac_height));
        glScalef(ac_length/12,ac_height/12,ac_width/5);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0, 0, 0);
        glPopMatrix();
        }

        int ac_c=0;
        for(int i=0;i<100;i++)
        {
        glPushMatrix();
        glTranslatef(5,4,-(ac_height-0.5));
        glRotatef(ac_c,0,0,1);
        glScalef(ac_length/12,ac_height/20,ac_width/4);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.098, 0.098, 0.439);
        glPopMatrix();
        ac_c+=5;
        }

        glPushMatrix();
        glTranslatef(0,1,-(ac_height-0.5));
        glScalef(ac_length/2,ac_height/2,ac_width/5);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.753, 0.753, 0.753);
        glPopMatrix();

         ac_c=0;
        for(float n=1.3;n<=3.5;n+=2)
        for(int i=0;i<100;i++)
        {
        glPushMatrix();
        glTranslatef(n,2,-(ac_height-0.5));
        glRotatef(ac_c,0,0,1);
        glScalef(ac_length/16,ac_height/20,ac_width/4);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.000, 0.502, 0.502);
        glPopMatrix();
        ac_c+=5;
        }


}

void light()
{
   float light_length = 20, light_width = 1, light_height = 2;
   float bar_length = 1, bar_height = light_height+1, bar_width = 2;

    //light-holder
   glPushMatrix();
   glScalef(light_length,light_height+1,light_width);
   glTranslatef(-0.5,0,-0.5);
   //cube(0.000, 0.000, 0.000);
   cube(1.000, 1.000, 1.000);
   glPopMatrix();

   //light bar
   for(int i=-1;i<=1;i+=2)
   {
       glPushMatrix();
   glTranslatef(i*(light_length/2-bar_length/2),0,0);
   glScalef(bar_length,bar_height,bar_width);
   glTranslatef(-0.5,0,-0.5);
   //cube(0.000, 0.000, 0.000);
   cube(	0.855, 0.647, 0.125);
   glPopMatrix();
   }

}

void room()
{
    float room_length = 70, room_height = 60, room_width = 70, flr_dense = 0.3;

    //floor
        glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(room_length,flr_dense,room_width);
    glTranslatef(-0.5,-1,-0.5);
    //cube(0.467, 0.533, 0.60);
    cube(0.961, 1.000, 0.980);
    glPopMatrix();
    //roof
    glPushMatrix();
    glTranslatef(0,1*room_height,0);
    glScalef(room_length,flr_dense,room_width);
    glTranslatef(-0.5,-1,-0.5);
    //cube(0.467, 0.533, 0.60);
    cube(0.741, 0.718, 0.420);
    glPopMatrix();

    //floor line
    for(int i=-(room_length/2);i<=(room_length)/2;i+=5)
    {
    glPushMatrix();
    glTranslatef(i,0.1,0);
    glScalef(flr_dense/4,flr_dense,room_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.000, 0.000, 0.0);
    glPopMatrix();
    }

    for(int i=-(room_width/2);i<=(room_width)/2;i+=5)
    {
    glPushMatrix();
    glTranslatef(0,0.1,i);
    glScalef(room_length,flr_dense,flr_dense/4);
    glTranslatef(-0.5,-1,-0.5);
    //cube(1.000, 1.000, 0.878);
    cube(0.000, 0.000, 0.0);
    glPopMatrix();
    }


    //side-wall
    for(int i=-1;i<=1;i+=2)
    {
    glPushMatrix();
    glTranslatef(i*(room_length/2-flr_dense/2),0,0);
    glScalef(flr_dense,room_height,room_width);
    glTranslatef(-0.5,0,-0.5);
    //cube(1.000, 0.871, 0.678);
    cube(0.741, 0.718, 0.420);
    glPopMatrix();
    }

    //back-front wall
    glPushMatrix();
    glTranslatef(0,0,-(room_width/2-flr_dense/2));
    glScalef(room_length,room_height,flr_dense);
    glTranslatef(-0.5,0,-0.5);
    cube(0.741, 0.718, 0.420);
    glPopMatrix();

    //board
    glPushMatrix();
    glTranslatef(0,room_height/2-room_height/4+4,-(room_width/2-flr_dense/2-3));
    glScalef(room_length/2,room_height/2,flr_dense);
    glTranslatef(-0.5,0,-0.5);
    cube(1,1,1);
    glPopMatrix();

    //board border
    for(int i=1;i<=3;i+=2)
    {
    glPushMatrix();
    glTranslatef(0,i*(room_height/2-room_height/4)+4,-(room_width/2-flr_dense/2-5));
    glScalef(room_length/2,flr_dense,flr_dense);
    glTranslatef(-0.5,0,-0.5);
    cube(0.502, 0.502, 0.000);
    glPopMatrix();
    }
    for(int i=-1;i<=1;i+=2)
    {
    glPushMatrix();
    glTranslatef(i*(room_length/4-flr_dense/2),(room_height/2-room_height/4)+4,-(room_width/2-flr_dense/2-5));
    glScalef(flr_dense,room_height/2,flr_dense);
    glTranslatef(-0.5,0,-0.5);
    cube(0.502, 0.502, 0.000);
    glPopMatrix();
    }

    //side-light
    for(int i=-1;i<=1;i+=2)
    {
        glPushMatrix();
    glTranslatef(i*(room_length/2-3.5),room_height/1.3,8);
     glRotatef(-90,0,1,0);
    light();
    glPopMatrix();
    }


    //teacher-platform
    glPushMatrix();
    glTranslatef(0,0,-(room_width/2-flr_dense/2-7));
    glScalef(room_length-12,room_height/7,room_width/3);
    glTranslatef(-0.5,0,-0.5);
    cube(0.55, 0.47, 0.125);
    glPopMatrix();



    //fan
    for(int i=-1;i<=1;i+=2)
    {
        for(int j=-1;j<=1;j+=1)
        {
    glPushMatrix();
    glTranslatef(i*(room_length/2-9),room_height-3,j*(room_width/2-8));
    glScalef(0.5,0.5,0.5);
    glTranslatef(-0.5,-1,-0.5);
    fan();
    glPopMatrix();
        }
    }

    //almirah
    glPushMatrix();
    glTranslatef(room_length/2-3.5,0,-3.3);
    glRotatef(-90,0,1,0);
    glScalef(2,3,0.2);
    almirah();
    glPopMatrix();

    //book shelf
    glPushMatrix();
    glTranslatef(-(room_length/2-3.5),0,-1.3);
    glRotatef(90,0,1,0);
    glScalef(1,2,0.2);
    shelf();
    glPopMatrix();

    //ac
    glPushMatrix();
    //glTranslatef(0,5,-1.3);
    //glRotatef(180,0,1,0);
    glScalef(1,10,1);
    glTranslatef(-0.5,0,-0.5);
    cube();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,5,-1.3);
    glRotatef(180,0,1,0);
    //glScalef(1,2,1);
    ac();
    glPopMatrix();

}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int lim = 7;
    glFrustum(-lim, lim, -lim, lim, 4, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, window_width, window_height);


    glRotatef(rot, 0,1,0);
    axes();

//    glPushMatrix();
//    glRotatef(180,0,1,0);
//    glScalef(0.75,0.75,0.75);
//    chair();
//    glPopMatrix();
//

    //ac();
   room();
   //fan();
   //light();
   //chair();
   //table();
   //almirah();
   //shelf();




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
    glutInitWindowSize(window_width,window_height);
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
