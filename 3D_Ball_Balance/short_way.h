

void short_way()
{
    //port -3
    float way_len = 15, way_height = 6, way_width = 50;

    //position check
    bool here = position_check(way_len/2, way_height/2, way_width/2, 100-(10+way_width/2));
    if(here)
    {
        port[3]=1;
         ball_speed_in = true;
         store_ball_pos(1);

    }
    else
    {
        port[3] = 0;
        fall_detection();
    }
    glPushMatrix();
    glTranslatef(0,0,100-(10+way_width/2));

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 14);

    glPushMatrix();
    glScalef(way_len, way_height, way_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0.5,0.5,0,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();



    //port -4
    bool there = position_check(4*way_width/2, way_height/2, way_len/2, 100-(10+way_width+way_len/2));
    if(there)
    {
        port[4] = 1;
        ball_speed_in = true;
        store_ball_pos(1);
    }
    else
    {
        port[4] = 0;
        //ball_speed_in = false;
        fall_detection();
    }
    glPushMatrix();
    glTranslatef(0,0,100-(10+way_width+way_len/2));

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 14);

    glPushMatrix();
    glScalef(4*way_width, way_height, way_len);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0.5,0.5,0,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();


    //join pillar
    for(int i=-1; i<=1; i++)
    {
        glPushMatrix();
        glTranslatef(i*(4*way_width)/2,0,100-(10+way_width+way_len/2));

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 14);

        glPushMatrix();
        glTranslatef(0,-250,0);
        glScalef(10, 500, 10);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0,0,0,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);

        glPopMatrix();
    }


}
