

void back_side(float back_side_len = 2000, float back_side_height = 1250, float back_side_width = 1)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 9);
    glPushMatrix();
    glTranslatef(250,back_side_height/2-80,-500);
    glScalef(back_side_len, back_side_height, back_side_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,1,1,0,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
