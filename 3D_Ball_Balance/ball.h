float radius = 8;
float ball_x_pos = 0, ball_y_pos = radius+(0.5/2), ball_z_pos = 0;
float ball_rot = 0;

void ball()
{
    glPushMatrix();
    glTranslatef(ball_x_pos, ball_y_pos, ball_z_pos);
    glutSolidSphere(radius,16,40);
    glPopMatrix();
}
