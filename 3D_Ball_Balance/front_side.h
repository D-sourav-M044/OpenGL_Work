

void front_side(float front_side_len = 2000, float front_side_height = 1250, float front_side_width = 1)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 16);
    glPushMatrix();
    glTranslatef(250,front_side_height/2-80,500);
    glScalef(front_side_len, front_side_height, front_side_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,1,1,0,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

