

float f_y =0, f_yi = 1.5;
void f_up()
{

    f_y += f_yi;
    if(f_y>=500)
        f_yi = -1.5;
    if(f_y<=0)
        f_yi = 1.5;

    glutPostRedisplay();
}

void end_scene_timer(int val)
{

    glDisable(GL_LIGHTING);
    end_scen_enable = val;
    glutPostRedisplay();
}

void finishing_flr()
{


    //port -7
    float f_len = 50, f_height = 6, f_width = 40;
    //position check
    bool here = position_check(f_len/2, f_y+150+f_height/2, f_width/2, -220,1,325);
    //bool here = position_check(f_len/2, f_y+f_height/2, f_width/2, -220,1,325);
    if(here)
    {
        port[7]=1;

        ball_pos_y += f_yi;
        eye[1] += f_yi;
        look[1] += f_yi;
        store_ball_pos(1);
        f_up();
        glutTimerFunc(2000,end_scene_timer,1);
    }
    else
    {
        port[7] = 0;
        fall_detection();
    }

    glPushMatrix();
    glTranslatef(0,f_y,0);
    glTranslatef(325,150,-220);
    // glTranslatef(325,0,-220);


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,20);
    glPushMatrix();
    glScalef(f_len,f_height,f_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0,0,0.5);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
//
    for(int i=-1; i<=1; i+=2)
    {
        for(int j=-1; j<=1; j+=2)
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,6);
            glPushMatrix();
            glTranslatef(i*(f_len/2+2.5),6,j*(f_width/2-2));
            glRotatef(45,0,0,i);
            glScalef(10,2,2);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0,0,0.5);
            glPopMatrix();
//
            glPushMatrix();
            glTranslatef(i*(f_len/2+6),10-2.5,j*(f_width/2-2));
            //glRotatef(45,0,0,i);
            glScalef(2,5,2);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.5,0,0.5);
            glPopMatrix();
            glDisable(GL_TEXTURE_2D);
//
//
            glPushMatrix();
            glTranslatef(i*(f_len/2+6),0,j*(f_width/2-2));
            glScalef(0.1,0.1,0.1);
            fire();
            cube();
            glPopMatrix();

        }
    }
    glPopMatrix();
}
