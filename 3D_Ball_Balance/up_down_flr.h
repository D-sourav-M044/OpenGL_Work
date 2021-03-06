float u_d = 0, u_d_i = 1;
bool side_cube = true;
bool on = true;
void make_on(int val)
{
    on = true;
}
void up_down()
{
    if(on)
    {
        u_d += u_d_i;
        if(u_d>=150)
            u_d_i = -1;
        else if(u_d<0)
            u_d_i = 1;

        if(u_d == 0 || u_d == 150)
        {
            on = false;
            glutTimerFunc(2000,make_on,1);
        }
    }

    glutPostRedisplay();
}

void up_down_flr()
{
    //port -2
    float len = 100, height = 6, width = 40;
    bool here = position_check(len/2, u_d+height/2, width/2, -220,1,400);
    if(here)
    {
        //cout<<"here"<<endl;
        port[2] = 1;
        if(on)
        {
            ball_pos_y += u_d_i;
            eye[1] += u_d_i;
            look[1] += u_d_i;
        }
        store_ball_pos(1);
        //cout<<"ball "<<ball_pos_y<<endl;
        //cout<<"plt "<<u_d+height/2<<endl;

    }
    else if(!here)
    {
        port[2] = 0;
        //cout<<"nah"<<endl;
        fall_detection();
    }

    //glPushMatrix();
    //glTranslatef(400,0,-220);

    glPushMatrix();
    glTranslatef(0,u_d,0);
    //glTranslatef(0,0,-30);
    glTranslatef(400,0,-220);





    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,27);

    glPushMatrix();
    glScalef(len, height, width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0.5,0.5);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //bar
    float bar_len = 20, bar_height = 70, bar_width = 5;
    for(int i=-1; i<=1; i+=2)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,5);

        glPushMatrix();

        glTranslatef(i*(len/2-bar_len/2),(bar_height/2-height/2),-(width/2-bar_width/2-0.5));
        glScalef(bar_len, bar_height, bar_width);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0.5,0.5,side_cube);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }

    //pipe
    float pipe_len = 2, pipe_height = 300, pipe_width = 2;
    glPushMatrix();
    glTranslatef(0,-pipe_height/2,0);
    glScalef(pipe_len, pipe_height, pipe_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0,0.5);
    glPopMatrix();


    up_down();
    glPopMatrix();

    // glPopMatrix();

}
