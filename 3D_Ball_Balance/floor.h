float i= 0;
float inc = 0.25;
bool flag = false;
bool flr_move = false;
bool ok = true;

void on_move(int val)
{
    ok = val;
    flr_move = val;
}

void flor_rot()
{
    if(ok && flr_move)
    {
        i+= inc;
        if(i>30)
        {
            inc = -0.25;
        }

        else if(i<-30)
            inc = 0.25;
        if (i==0)
        {
            ok= false;
            flr_move = false;
            glutTimerFunc(1000,on_move,1);
        }
    }
    else
    {
        i=0;
    }


    glutPostRedisplay();
}




void floor()
{
    bool here = false;
    float len = 70, height = 6, width = 20;

    here = position_check(len/2, height/2, width/2,0,1);
    flag = here;
    ok_ball = here;
    flr_move = here;
    if(here && flr_move && ok)
    {
        port[1] = 1;

        ball_int_rot -= 5;
        ball_int_rot_z = 1;

        surface_len = len, surface_height = height, surface_width = width;
        ball_pos_x -= 1.5*(len/2*sin((inc*3.1416)/180));
        if(ball_rot<=i)
            ball_rot += inc;
        ball_rot_z = 1;
    }
    else if(here == 0)
    {


        port[1] = 0;
        fall_detection(inc);
        ball_rot = 0;
    }

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 1);
    glPushMatrix();
    glRotatef(i,0,0,1);

    glPushMatrix();
    glScalef(len,height,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0.5,1,0,1);
    glPopMatrix();

    flor_rot();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}
