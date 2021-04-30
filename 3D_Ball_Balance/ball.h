
float radius = 4;
float ball_x_pos = 0, ball_y_pos = radius+(0.5/2), ball_z_pos = 0;
float ball_rot = 0;
int ball_rot_x = 0, ball_rot_y = 0, ball_rot_z = 0;



void ball()
{

        glPushMatrix();
        //glRotatef(ball_rot,ball_rot_x,ball_rot_y,ball_rot_z);
    glPushMatrix();

    glTranslatef(ball_x_pos, ball_y_pos, ball_z_pos);
    glutSolidSphere(radius,16,40);
    glPopMatrix();
    glPopMatrix();
}
