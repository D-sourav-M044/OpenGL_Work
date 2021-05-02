
void normal_flr()
{
    // area_no ---------- 0
    float len = 100, height = 6, width = 20;

    load_area(0, 100, 6, 200);

    bool here = position_check(len/2, height/2, width/2, 10+width/2);
    if(here)
    {
        ok_ball = true;
        port[0]=1;
    }
    else
    {
        port[0] = 0;
        fall_detection();
        ok_ball = false;
    }
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    glPushMatrix();
    glTranslatef(0,0,10+width/2);
    glScalef(len,height,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0,0);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
