

void side_wall(float back_side_len = 1000, float back_side_height = 1000, float back_side_width = 1)
{
    //dragon block
    float d_len = 500, d_height =1400, d_width = 1;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 11);

    glPushMatrix();
    glTranslatef(-550,back_side_height/2-100,-300);
       glRotatef(2,0,0,-1);
    glRotatef(-90,0,1,0);
    glScalef(d_len, d_height, d_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,1,1,0,1);
    water_flow();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void
