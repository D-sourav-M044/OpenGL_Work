


void normal_flr()
{
    // area_no ---------- 0
    float len = 100, height = 6, width = 80;

    load_area(0, 100, 6, 200);

    bool here = position_check(len/2, height/2, width/2, 100+10+width/2);
    if(here)
    {

        ok_ball = true;
        port[0]=1;
    }
    else
    {
        port[0] = 0;
        fall_detection();
        //ok_ball = false;
    }
    glPushMatrix();
    glTranslatef(0,0,100+10+width/2);



    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    glPushMatrix();
    glScalef(len,height,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0,0);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

   //back_support
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);

    glPushMatrix();
    glTranslatef(0,0,width);
    glScalef(2*len,100*height,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


//handle
     for(int tr_x = -1; tr_x<=1; tr_x+=2)
    {
    glPushMatrix();
    glTranslatef(tr_x*(len/2-2.5), 60,0);
    glScalef(5,10,80);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0.4,0.2);
    glPopMatrix();
    }
     for(int tr_x = -1; tr_x<=1; tr_x+=2)
    {
        for(int tr_z = -1; tr_z<=1; tr_z+=2)
    {
    glPushMatrix();
    glTranslatef(tr_x*(len/2-2.5), 30, tr_z*(width/2-2.5));
    glScalef(5,60,5);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0.4,0.2);
    glPopMatrix();
    }
    }
    //support wire
    for(int tr_x = -1; tr_x<=1; tr_x+=2)
    {
        for(int i=-width/2; i<=width/2; i+=10)
        {
            glPushMatrix();
            glTranslatef(tr_x*len/2, 60+((width-i)*cos(45))+width/16, i+sin(45)*(((width/2-i)*sin(45)))+width/4);
            glRotatef(45,1,0,0);
            glScalef(0.5,2*((width-i)*sin(45)),0.5);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.5,0.4,0.2);
            glPopMatrix();
        }

    }



    glPopMatrix();



}
