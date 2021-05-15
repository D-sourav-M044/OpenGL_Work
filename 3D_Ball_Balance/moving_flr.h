
float fan_rt = 0;

float move_var = 0, move_ind = 1;
bool move_on = true;
void flr_move_on(int val)
{
    move_on = true;
}
void _move()
{
    if(move_on)
    {
        move_var += move_ind;
        if(move_var>=220.50)
            move_ind = -1;
        else if(move_var<=0)
            move_ind = 1;

        if(move_var == 0 || move_var >=220.50)
        {
            move_on = false;
            glutTimerFunc(2000,flr_move_on,1);
        }
    }

    glutPostRedisplay();
}

void fan_rotation()
{
    if(1)
    {
        fan_rt = fan_rt+2;
        if(fan_rt>360)
            fan_rt =0;

    }
    else
    {
        ;
    }
    glutPostRedisplay();
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
        glScalef(base/4,base/4,base/4);
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
        glTranslatef((2*base)/2,base/8,0);
        glScalef(2*base,0.2*base,base/2);
        glTranslatef(-0.5,0.0,-0.5);
        cube(0.1, 0.4, 0.3);
        glPopMatrix();
    }

    fan_rotation();
    glPopMatrix();

}


void moving_flr()
{
//    //port -6
    float len = 100, height = 6, width = 40;
    bool here = position_check((len+25)/2, height/2, (width+25)/2,(width+25)/2,1,move_var+100+(len+25)/2);
//
//
    if(here)
    {
        cout<<"here"<<endl;
        port[6] = 1;
        if(move_on)
        {
             ball_pos_x += move_ind;
        eye[0] += move_ind;
        look[0] += move_ind;
        }


        //cout<<"ball "<<ball_pos_y<<endl;
        //cout<<"plt "<<move_var+height/2<<endl;

    }
    else if(!here)
    {
        port[6] = 0;
        //cout<<"nah"<<endl;
        fall_detection();
    }
    glPushMatrix();
    glTranslatef(move_var,0,0);
    glTranslatef(100+(len+25)/2,0,(width+25)/2);

    //flr
    for(int i=0; i<=1; i++)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,17);

        glPushMatrix();
        glTranslatef(0,i*90,0);
        glScalef(len+25, height, width+25);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0.5,0.5);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }



    //top
    for(int i=-1; i<=1; i+=2)
    {
        for(int j=-1; j<=1; j+=2)
        {
            glPushMatrix();

            glTranslatef(i*(len/8+5),120,j*(width/4+5));
            glRotatef(40,-j,0,i);
            glScalef(1,80,1);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.5,0, 0);
            glPopMatrix();
        }
    }
    //pipe for fan
    for(int i=-1; i<=1; i+=2)
    {
        for(int j=-1; j<=1; j+=2)
        {
            glPushMatrix();
            glTranslatef(i*(len/2),45,j*(width/2));
            glScalef(1,90,1);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.5,0, 0);
            glPopMatrix();
        }
    }

    //top-fan
    glPushMatrix();
    glTranslatef(0,160,0);
    glRotatef(180,1,0,0);
    glScalef(2,2,2);
    fan();
    glPopMatrix();

    //side-fan
    for(int i=-1; i<=1; i+=2)
    {
        for(int j=-1; j<=1; j+=2)
        {
            glPushMatrix();
            glTranslatef(i*((len)/2-10),-25,j*((width+30)/2-10));
            //glRotatef(90,-j*1,0,0);
            glScalef(2,2,2);
            fan();
            glPopMatrix();
        }
    }




    _move();
    glPopMatrix();

}
