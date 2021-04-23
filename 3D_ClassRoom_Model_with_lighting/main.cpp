#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

const int window_width = 1200;
const int window_height = 750;
int tty=0,ttx=0;
GLfloat eyeX = 0;
GLfloat eyeY = 40;   //40 //30  //5
GLfloat eyeZ = 50;  //50  //20


GLfloat lookX = 0;
GLfloat lookY = 40; //40  //0
GLfloat lookZ = -100;

//GLfloat eyeX = 0;
//GLfloat eyeY = 5;   //40 //30  //5
//GLfloat eyeZ = 30;  //50  //20
//
//
//GLfloat lookX = 0;
//GLfloat lookY = 5; //40  //0
//GLfloat lookZ = -100;

int up=0,down=0,r=0,l=0,f=0,b=0;

float rot = 0, fan_rt = 0;
bool light_1 = false, light_2 = false, light_3 = false ;

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
    {5,7,3,1},
    {0,4,5,1},
    {3,7,6,2},
    {0,1,3,2},
    {6,7,5,4}
};
static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void material_property(float R, float G, float B, bool li )
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { R, G, B, 1.0 };
    GLfloat mat_diffuse[] = { R, G, B, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_emission[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {10};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission);


    if((light_1 || light_2 || light_3) && li)
    {
        glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission);
        //cout<<"if "<<li<<endl;
    }

    else
    {
        glMaterialfv( GL_FRONT, GL_EMISSION, no_mat);
         //cout<<"else "<<li<<endl;
    }



}


void cube(float R=0.5, float G=0.5, float B=0.5, bool li = false)
{
    material_property(R,G,B,li);
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        glColor3f(R,G,B);

        R += 0.05;
        G += 0.05;
        B += 0.05;
    getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}


void drawText(const char *text, int length, int x, int y)
{
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX,matrix);
    glLoadIdentity();
    glOrtho(0,800,0,600,-5,5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0; i<length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
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
    cube(0.737, 0.561, 0.561);
    glPopMatrix();

    //side bar
    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*(top_length/2-3*top_height/2),0,0);
        glScalef(top_height,top_length,top_width);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.737, 0.561, 0.561);
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef((top_length/2-6.1),0,0);
    glScalef(top_height,top_length,top_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.737, 0.561, 0.561);
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

    float seat_length =12, seat_height =2, seat_width  =8;

    float leg_length  = 1, leg_height  = 20, leg_width  = 0.8;

    //seat
    glPushMatrix();
    glScalef(seat_length,seat_height,seat_width);
    glTranslatef(-0.5,0,-0.5);
    cube(0.184, 0.310, 0.310);
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

    // handle

    for(int i=-1;i<=1;i+=2)
    {
        //verticale
        glPushMatrix();
    glTranslatef(i*(seat_length/2-leg_width/2),leg_height/2,0);
    glScalef(leg_width,leg_width,seat_width-leg_width/2);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();

    //horizontal

    glPushMatrix();
    glTranslatef(i*(seat_length/2-leg_width/2),leg_height/2,(seat_width/2-leg_width/2));
    glScalef(leg_width,leg_height/2,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.45,0.49,0.28);
    glPopMatrix();
    }




    //Rail-upper
    for(int i=10;i<=20;i+=2)
    {
        glPushMatrix();
    glTranslatef(0,i,-(seat_width/2-leg_width/2));
    glScalef(seat_length,seat_height/2,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.184, 0.310, 0.310);
    glPopMatrix();
    }



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

void door()
{
    float length = 5, width = 5, height =10;
    glPushMatrix();
    glScalef(length,height,width);
    glTranslatef(-0.5,0,-0.5);
    cube(0.235, 0.702, 0.443);
    glPopMatrix();
    //right-middle-left bar
    for(int i=-1; i<=1; i++)
    {
        glPushMatrix();
        glTranslatef(i*(length/2),0,width/2);
        glScalef(0.3,height,6);
        glTranslatef(-0.5,0,-0.5);
        cube(0.722, 0.525, 0.043);
        glPopMatrix();
    }
    //top-bottom bar
    for(int i=0; i<=1; i++)
    {
        glPushMatrix();
        glTranslatef(0,i*(height),width/2);
        glScalef(length,0.3,6);
        glTranslatef(-0.5,0,-0.5);
        cube(0.722, 0.525, 0.043);
        glPopMatrix();
    }


    //white handle
    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*0.3,height/2,width/2);
        glScalef(0.3,1,0.5);
        glTranslatef(-0.5,0,-0.5);
        //cube(0.53,0.55,0.28);
        cube(1,1, 1.000);
        glPopMatrix();
    }

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

void t_desk()
{
    float desk_length = 10, desk_height = 30, desk_width = 5;
    float side_dense = 0.3;

    //top space
    glPushMatrix();
    glTranslatef(0,desk_height,0);
    glRotatef(-30,1,0,0);
    glScalef(desk_length+2,side_dense,desk_width+5);
    glTranslatef(-0.5,0,-0.5);
    cube(0.804, 0.522, 0.247);
    glPopMatrix();

    //fron-back side bar
    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(0,0,i*(desk_width/2-side_dense/2));
        glScalef(desk_length,desk_height+(i*2),side_dense);
        glTranslatef(-0.5,0,-0.5);
        cube(0.545, 0.271, 0.075);
        glPopMatrix();
    }

    //left-right side bar

    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*(desk_length/2-side_dense/2),0,0);
        glScalef(side_dense,desk_height-2,desk_width);
        glTranslatef(-0.5,0,-0.5);
        cube(0.545, 0.271, 0.075);
        glPopMatrix();
    }
    //bottom space
    glPushMatrix();
    glScalef(desk_length+2,side_dense,desk_width+5);
    glTranslatef(-0.5,0,-0.5);
    cube(0.804, 0.522, 0.247);
    glPopMatrix();

    //mouth speaker
    glPushMatrix();
    glTranslatef(-desk_length/2,desk_height,0);
    glScalef(side_dense,0.75*desk_width,side_dense);
    glTranslatef(-0.5,0,-0.5);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-desk_length/2,desk_height+0.75*desk_width,0);
    glRotatef(-30,1,0,0);
    glScalef(side_dense,0.75*desk_width,side_dense);
    glTranslatef(-0.5,0,-0.5);
    cube(0,0,0);
    glPopMatrix();

    int r = 0;
    glPushMatrix();
    glRotatef(-3.5,1,0,0);
    for(int i=0; i<200; i++)
    {
        glPushMatrix();
        glTranslatef(-desk_length/2,(desk_height+1.5*desk_width),0);
        glRotatef(r,0,1,0);
        glScalef(4*side_dense,4*side_dense,4*side_dense);
        glTranslatef(-0.5,0,-0.5);
        cube(0,0,0);
        glPopMatrix();
        r+=5;
    }
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
        cube(	0.373, 0.620, 0.627);
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
    for(float i=0.5; i<=1.5; i+=0.5)
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
    for(int i=-1; i<=1; i+=1)
    {
        glPushMatrix();
        glTranslatef((i)*(ac_length/2-ac_length/10),2,-(ac_height));
        glScalef(ac_length/12,ac_height/12,ac_width/5);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0, 0, 0);
        glPopMatrix();
    }

    int ac_c=0;
    for(int i=0; i<100; i++)
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
    for(float n=1.3; n<=3.5; n+=2)
        for(int i=0; i<100; i++)
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

void light(int light_status)
{
    float light_length = 20, light_width = 1, light_height = 2;
    float bar_length = 2, bar_height = light_height+1, bar_width = 2;

    //light-holder
    glPushMatrix();
    glScalef(light_length-2,light_height+1,light_width);
    glTranslatef(-0.5,0,-0.5);
    cube(1.000, 0.000, 1.000,light_status);
    glPopMatrix();

    //light bar
    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*(light_length/2-bar_length/2),0,0);
        glScalef(bar_length,bar_height,bar_width);
        glTranslatef(-0.5,0,-0.5);
        cube(0.855, 0.647, 0.125);
        glPopMatrix();
    }

}

void window()
{
    float window_length = 10, window_height = 15, window_width = 0.5;
    float bar_dense = 0.3;
    //window blue glass
    glPushMatrix();
    glScalef(window_length-2,window_height,window_width);
    glTranslatef(-0.5,0.0,-0.5);
    cube(0.275, 0.510, 0.706);
    glPopMatrix();

    //side bar
    for(int i=0; i<=1; i++)
    {
        glPushMatrix();
        glTranslatef(0,i*(window_height-(3*bar_dense)/2-0.3),bar_dense/2);
        glScalef(window_length,3*bar_dense,bar_dense);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.65,0.4,0.3);
        glPopMatrix();
    }
    //right-middle-left bar
    for(int i=-1; i<=1; i+=1)
    {
        glPushMatrix();
        glTranslatef(i*(window_length/2-(4*bar_dense)/2),0,bar_dense/2);
        glScalef(4*bar_dense,window_height,bar_dense);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.65,0.4,0.3);
        glPopMatrix();
    }
    //row line
    for(int i=-1; i<=1; i+=1)
    {
        for(int j=2.5; j<=5; j*=2)
        {
            glPushMatrix();
            glTranslatef(i*(window_length/2-bar_dense/2-j),0,bar_dense/2);
            glScalef(bar_dense,window_height,bar_dense);
            glTranslatef(-0.5,0.0,-0.5);
            cube(0.4,0.4,0.3);
            glPopMatrix();
        }
    }
    //col line
    for(int i=-1; i<=1; i+=2)
    {
        for(int j=1; j<=2; j++)
        {
            glPushMatrix();
            glTranslatef(i*(window_length/4),j*(window_height/3),bar_dense/2-0.005);
            glScalef(window_length/2,bar_dense,bar_dense);
            glTranslatef(-0.5,0.0,-0.5);
            cube(0.4,0.4,0.3);
            glPopMatrix();
        }
    }

    //golden handle
    int c=0;
    for(float i=-0.3; i<=0.3; i+=0.6)
    {
        glPushMatrix();
        glTranslatef(i,(window_height/2),bar_dense);
        glScalef(bar_dense,10*bar_dense,bar_dense);
        glTranslatef(-0.5,0.0,-0.5);
        cube(1, 1, 1);
        glPopMatrix();
    }



}

void st_desk()
{
    glPushMatrix();
    glTranslatef(0,-8,0);
    glScalef(1,2,1);
    table();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,-4.5,15);
    glRotatef(180,0,1,0);
    glScalef(1,1.5,0.7);
    chair();
    glPopMatrix();
}

void brick_wall(float len,float he,float wi)
{
    len = 90, he = 60, wi = 100;
    float b_len = 1, b_he= 1, b_w = 0.5;
    for(float i=-he/2; i<=he/2; i+=1.2)
    {
        for(float j=-len/2; j<=len/2; j+=1.2)
        {
            glPushMatrix();
            glTranslatef(j,i,0);
            glScalef(b_len,b_he,b_w);
            cube(0.5,0.3,0.4);
            glPopMatrix();
        }
    }
}

void point_light_effect(int light_no,float x, float y, float z)
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.0, 0.0, 0.0, 0.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    //GLfloat light_position[] = { ttx,tty-10,0, 1.0 };
    GLfloat light_position[] = { x,y,z, 1.0 };

    if(light_no == 1)
    {
        glEnable( GL_LIGHT1);

        if(light_1)
        {
            glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
            glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
            glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
        }
        else
        {
            glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
            glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);
            glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);

        }
        glLightfv( GL_LIGHT1, GL_POSITION, light_position);
    }

    else
    {
        glEnable( GL_LIGHT2);

        if(light_2)
        {
            glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient);
            glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse);
            glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular);
        }
        else
        {
            glLightfv( GL_LIGHT2, GL_AMBIENT, no_light);
            glLightfv( GL_LIGHT2, GL_DIFFUSE, no_light);
            glLightfv( GL_LIGHT2, GL_SPECULAR, no_light);
        }
        glLightfv( GL_LIGHT2, GL_POSITION, light_position);
    }


}

void room()
{
    float room_length = 90, room_height = 60, room_width = 100, flr_dense = 0.3;

    //floor
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(room_length,flr_dense,room_width);
    glTranslatef(-0.5,-1,-0.5);
    //cube(0.467, 0.533, 0.60);
    cube(0.502, 0.502, 0.502);
    glPopMatrix();
    //roof
    glPushMatrix();
    glTranslatef(0,1*room_height,0);
    glScalef(room_length,flr_dense,room_width);
    glTranslatef(-0.5,-1,-0.5);
    //cube(0.7,0.7,0.7);
    cube(0.741, 0.718, 0.420);
    glPopMatrix();

    //floor line
    for(int i=-(room_length/2); i<=(room_length)/2; i+=5)
    {
        glPushMatrix();
        glTranslatef(i,0.1,0);
        glScalef(flr_dense/4,flr_dense,room_width);
        glTranslatef(-0.5,-1,-0.5);
        cube(0.000, 0.000, 0.0);
        glPopMatrix();
    }

    for(int i=-(room_width/2); i<=(room_width)/2; i+=5)
    {
        glPushMatrix();
        glTranslatef(0,0.1,i);
        glScalef(room_length,flr_dense,flr_dense/4);
        glTranslatef(-0.5,-1,-0.5);
        cube(0.000, 0.000, 0.0);
        glPopMatrix();
    }


    //side-wall
    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*(room_length/2-flr_dense/2),0,0);
        glScalef(flr_dense,room_height,room_width);
        glTranslatef(-0.5,0,-0.5);
        //cube(1.000, 0.871, 0.678);
        cube(0.741, 0.718, 0.420);
        glPopMatrix();
    }

    //front wall
    glPushMatrix();
    glTranslatef(0,0,-(room_width/2-flr_dense/2));
    glScalef(room_length,room_height,flr_dense);
    glTranslatef(-0.5,0,-0.5);
    cube(0,0,0);
    //cube(0.373, 0.620, 0.627);
    glPopMatrix();

    //back wall
    glPushMatrix();
    glTranslatef(0,0,(room_width/2-flr_dense/2));
    glScalef(room_length,room_height,flr_dense);
    glTranslatef(-0.5,0,-0.5);
    //cube(0.741, 0.718, 0.420);
    cube(0.741, 0.718, 0.420);
    glPopMatrix();


    //board
    glPushMatrix();
    glTranslatef(0,room_height/2-room_height/4+4,-(room_width/2-flr_dense/2-3));
    glScalef(room_length/1.5,room_height/2,flr_dense);
    glTranslatef(-0.5,0,-0.5);
    cube(0,1,0);
    glPopMatrix();

    //board border
    for(int i=1; i<=3; i+=2)
    {
        glPushMatrix();
        glTranslatef(0,i*(room_height/2-room_height/4)+3,-(room_width/2-flr_dense/2-6));
        glScalef(room_length/1.5,5*flr_dense,flr_dense);
        glTranslatef(-0.5,0,-0.5);
        cube(0.502, 0.502, 0.000);
        glPopMatrix();
    }
    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*(room_length/3-flr_dense/2),(room_height/2-room_height/4)+4,-(room_width/2-flr_dense/2-6));
        glScalef(5*flr_dense,room_height/2,flr_dense);
        glTranslatef(-0.5,0,-0.5);
        cube(0.502, 0.502, 0.000);
        glPopMatrix();
    }

    //side-light--1
//    for(int i=-1; i<=1; i+=2)
//    {
        glPushMatrix();
        glTranslatef(-(room_length/2-3.5),room_height/1.3,20);
        glRotatef(-90,0,1,0);
        glScalef(0.5,1,1);
        light(light_1);
        glPopMatrix();

    glPushMatrix();
   // glRotatef(90,0,1,0);
    point_light_effect(1,-(room_length/2-3.5),room_height/1.3,20);
    glTranslatef(-0.5,-0.5,-0.5);
    glPopMatrix();
//    }

//        //sight light -2
        glPushMatrix();
        glTranslatef((room_length/2-3.5),room_height/1.3,20);
        glRotatef(270,0,1,0);
        glScalef(0.5,1,1);
        light(light_2);
        glPopMatrix();

        glPushMatrix();
        //glRotatef(270,0,1,0);
        point_light_effect(2,(room_length/2-3.5),room_height/1.3,20);
        glTranslatef(-0.5,-0.5,-0.5);
        glPopMatrix();





    //teacher-platform
    glPushMatrix();
    glTranslatef(0,0,-(room_width/2-flr_dense/2-7));
    glScalef(room_length-12,room_height/7,room_width/9);
    glTranslatef(-0.5,0,-0.5);
    cube(0.55, 0.47, 0.125);
    glPopMatrix();



    //fan
    for(int i=-1; i<=1; i+=2)
    {
        for(int j=-1; j<=1; j+=1)
        {
            glPushMatrix();
            glTranslatef(i*(room_length/2-15),room_height-7,j*(room_width/2-8));
            glScalef(1,1,1);
            glTranslatef(-0.5,-1,-0.5);
            fan();
            glPopMatrix();
        }
    }

    //door
    glPushMatrix();
    glTranslatef(room_length/2-0.5,0,-12);
    glRotatef(-90,0,1,0);
    glScalef(2,4,0.2);
    door();
    glPopMatrix();

    //book shelf
    glPushMatrix();
    glTranslatef(-(room_length/2-3.5),30,0);
    glRotatef(90,0,1,0);
    glScalef(1,2,0.2);
    shelf();
    glPopMatrix();

    //projector
    //holder
    for(int i=-3; i<=3; i+=6)
    {
        glPushMatrix();
        glTranslatef(i,room_height/2+18.1,-1.3);
        //glRotatef(180,0,1,0);
        glScalef(1,12,1);
        glTranslatef(-0.5,0,-0.5);
        cube();
        glPopMatrix();
    }

    //pro_box
    glPushMatrix();
    glTranslatef(0,room_height/2+18,-1.3);
    glRotatef(180,0,1,0);
    //glScalef(1,2,1);
    ac();
    glPopMatrix();

    //ac
    glPushMatrix();
    glTranslatef(room_length/2,room_height/2+18,-4.3);
    glRotatef(270,0,1,0);
    glScalef(1,1,0.5);
    ac();
    glPopMatrix();

    //window
    glPushMatrix();
    glTranslatef(-(room_length/2),room_height/2-8,14);
    glRotatef(90,0,1,0);
    glScalef(1,1.5,2);
    window();
    glPopMatrix();

    //teacher desk
    glPushMatrix();
    glTranslatef(-(room_length/2-10),0,-16);
    glScalef(1,0.8,1);
    t_desk();
    glPopMatrix();

    //chair-table
    for(int i=5; i<=40; i+=15)
    {
        for(int j=-(room_length/2-10); j<=room_length/2; j+=22)
        {
            glPushMatrix();
            glTranslatef(j,10,i);
            glScalef(0.5,0.5,0.5);
            st_desk();
            glPopMatrix();
        }
    }


}




void li_obj()
{
    glPushMatrix();
    glTranslatef(ttx,tty,0);
    glScalef(5,1,1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,0,0); //RED Line
    glPopMatrix();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int lim = 8;
    glFrustum(-lim, lim, -lim, lim, 4, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, window_width, window_height);


    glRotatef(rot, 0,1,0);
    //std::string text = "CSE d";
    //drawText(text.data(),text.size(),50,0);
    axes();

    //ac();
    //li_obj();
    room();
    //fan();
    //light();
    //chair();
//    glPushMatrix();
//    glRotatef(45,0,1,0);
//    lighting_effect();
//    glTranslatef(-0.5,-0.5,-0.5);
//    glPopMatrix();

    //table();
    //door();
    //shelf();
    //window();
    //t_desk();
    //st_desk();
    //testflr();
    //brick_wall(90,60,100);

//    glPushMatrix();
//    glTranslatef(ttx,tty,0);
//    glScalef(5,1,1);
//    glTranslatef(-0.5,-0.5,-0.5);
//    cube(1,0,0,true); //RED Line
//    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        //for light
    case '1':
        light_1 = !light_1;
        break;
    case '2':
        light_2 = !light_2;
        break;
    case '3':
        light_3 = !light_3;
        break;

    case 'q':
        exit(0);
        break;
    // end of light

    case 'w':

        if(up<=11)
        {
            up++;
            down--;
            eyeY++;
            lookY++;
        }

        break;
    case 's':

        if(down<=30)
        {
            down++;
            up--;
            eyeY--;
            lookY--;

        }
        break;
    case 'a':
        //rot--;
        //eyeX++;
        lookX++;
        break;
    case 'd':
        //rot++;
        //eyeX++;
        lookX--;
        break;
    case 'e':
        rot--;
        break;
    case 'r':
        rot++;
        break;
    case 'l':
        if(r<=36)
        {
            r++;
            l--;
            eyeX++;
            lookX++;
        }
        break;
    case 'j':
        if(l<=36)
        {
            r--;
            l++;
            eyeX--;
            lookX--;
        }

        break;
    case '+':
        eyeZ--;
        //lookZ--;
        break;
    case 'i':
        if(f<=80)
        {
            f++;
            b--;
            eyeZ--;
        }

        break;
    case '-':
        eyeZ++;
        //lookZ--;
        break;
    case 'k':
        if(b<1)
        {
            b++;
            f--;
            eyeZ++;
        }

        break;
    }

    glutPostRedisplay();
}

void menu()
{
    cout<<"\t-------------------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<6; i++)
    {
        if(i==3)
        {
            cout<<"\t|            \t\t\t3D ClassRoom Model\t\t\t\t           |"<<endl;
        }

        cout<<"\t|            \t\t\t\t\t\t\t\t\t           |"<<endl;
    }
    cout<<"\t-------------------------------------------------------------------------------------------"<<endl;
    cout<<" \t\t| Controls |"<<endl;
    cout<<"\t\t-------------"<<endl<<endl;
    cout<<"                move forward"<<endl;
    cout<<"                     ^"<<endl;
    cout<<"                     |"<<endl<<endl;
    cout<<"                     i"<<endl;
    cout<<"  move left<--    j     l   --> move right"<<endl;
    cout<<"                     k"<<endl<<endl;
    cout<<"                     ^"<<endl;
    cout<<"                     |"<<endl;
    cout<<"                move backward"<<endl<<endl;;
    cout<<"\t-------------------------------------------------------------------------------------------"<<endl;
    cout<<"some more features"<<endl;
    cout<<"\tpress\t   +         to zoom in"<<endl;
    cout<<"\tpress\t   -         to zoom out"<<endl;
    cout<<"\tpress\t   w         to go up"<<endl;
    cout<<"\tpress\t   s         to go down"<<endl;
    cout<<"\tpress\t   a         to turn left"<<endl;
    cout<<"\tpress\t   d         to turn right"<<endl;
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(window_width,window_height);
    glutInitWindowPosition(300,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("3D Class Room Model");


    glutDisplayFunc(display);
    glutKeyboardFunc(key);


    glEnable(GL_DEPTH_TEST);
    glShadeModel( GL_SMOOTH );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);

    glEnable(GL_LIGHTING);


    menu();
    glutMainLoop();

    return EXIT_SUCCESS;
}