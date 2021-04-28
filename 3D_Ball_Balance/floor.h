float i= 0;
float inc = 0.25;
bool flag = true;
void flor_rot()
{
    i+= inc;
    if(i>50)
        inc = -0.25;
    else if(i<-50)
        inc = 0.25;

    glutPostRedisplay();
}




void floor()
{
    bool here = false;
    float len = 60, height = 0.5, width = 40;
    here = position_check(len/2, height/2, width/2);

    if(here)
    {
        ball_x_pos -= len/2*sin((inc*3.1416)/180);
        //ball_x_pos -= len/4*sin(0.25);
        //ball_y_pos -= len/2*cos((1*3.1416)/180);
        ball_rot += inc;
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
