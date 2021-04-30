float i= 0;
float inc = 0.25;
bool flag = true;
bool flr_move = false;
void flor_rot()
{
    flr_move = true;
    i+= inc;
    if(i>30)
        inc = -0.25;
    else if(i<-30)
        inc = 0.25;

    glutPostRedisplay();
}




void floor()
{
    bool here = false;
    float len = 60, height = 0.5, width = 40;
    here = position_check(len/2, height/2, width/2);
    if(here && flr_move)
    {
        ball_x_pos -= len/2*sin((inc*3.1416)/180);
        ball_rot += inc;
        ball_rot_z = 1;
        cout<<"it is here"<<endl;
    }
    else cout<<"no dude"<<endl;


    glPushMatrix();
    glRotatef(i,0,0,1);

    glPushMatrix();
    glScalef(60,0.5,40);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0,0.5);
    glPopMatrix();

    flor_rot();
    glPopMatrix();

}
