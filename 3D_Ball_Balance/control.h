
void control_cube()
{
    glPushMatrix();
    glTranslatef(-50,40,120);
    //glTranslatef(ball_pos_x-50,ball_pos_y+40,ball_pos_z);

    //light
//    glPushMatrix();
//    glTranslatef(0,20,0);
//    glScalef(100,10,1);
//    glTranslatef(-0.5,-0.5,-0.5);
//    cube(0.5,0.5,0.5,light_3);
//    spot_light_effect(-40,80,130, 10);
//    glPopMatrix();


    //arrow
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,26);

    glPushMatrix();
    glScalef(10,10,1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //a
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,25);

    glPushMatrix();
    glTranslatef(-10,0,0);
    glScalef(10,10,1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //d
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,24);

    glPushMatrix();
     glTranslatef(10,0,0);
    glScalef(10,10,1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //w
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,22);

    glPushMatrix();
    glTranslatef(0,10,0);
    glScalef(10,10,1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //s
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,23);

    glPushMatrix();
    glTranslatef(0,-10,0);
    glScalef(10,10,1);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}
