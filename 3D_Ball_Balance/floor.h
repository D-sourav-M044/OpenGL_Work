float i= 0;
float inc = 0.25;
bool flag = true;
bool flr_move = false;
void flor_rot()
{
    flr_move = true;
    i+= inc;
    if(i>30)
    {
        inc = -0.25;
        cout<<"minus"<<endl;
    }

    else if(i<-30)
        inc = 0.25;

    glutPostRedisplay();
}




void floor()
{
    bool here = false;
    float len = 60, height = 0.5, width = 20;
    here = position_check(len/2, height/2, width/2);
    if(here && flr_move)
    {
        surface_len = len, surface_height = height, surface_width = width;
        ball_pos_x -= 2*(len/2*sin((inc*3.1416)/180));
        if(ball_rot<=i)
            ball_rot += inc;
        ball_rot_z = 1;
        cout<<"it is here"<<endl;
    }
    else if(here == 0)
    {
        cout<<"no dude"<<endl;
        ball_fall = 1;
        ball_fall_rot = inc;



        if(i>0)
        {
            ball_fall_rot_z -= 1;
        }
        else
        {
            ball_fall_rot_z = 1;
        }
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
