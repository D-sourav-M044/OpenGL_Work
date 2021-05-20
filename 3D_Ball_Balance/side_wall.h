

void left_side_wall()
{
    //pyramid block
    float left_side_len = 500, left_side_height =1400, left_side_width = 1;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 11);

    glPushMatrix();
    glTranslatef(-800,left_side_height/2-100,-400);
    glRotatef(5,0,0,-1);
    glRotatef(-90,0,1,0);
    glScalef(left_side_len, left_side_height, left_side_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,1,1,0,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 21);

    glPushMatrix();
    glTranslatef(-800,left_side_height/2-100,100);
    glRotatef(5,0,0,-1);
    glRotatef(-90,0,1,0);
    glScalef(left_side_len, left_side_height, left_side_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,1,1,0,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}

