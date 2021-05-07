int rr = 0;
void testball()
{

    for(int i=0; i<100; i++)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,4);
        glPushMatrix();
        glRotatef(rr+1,-1,0,0);
        glPushMatrix();
        glRotatef(rr-2,0,1,0);
        glPushMatrix();
        glRotatef(rr,0,0,-1);
        glPushMatrix();
        glScalef(20,20,20);
        glTranslatef(-0.5,-0.5,-0.5);
        if(i%10==0)
            cube(0.5,0.1,0.1);
        else if(i%10==1)
            cube(0.5,0,0);
        else if(i%10==1)
            cube(0.5,0,0.5);
        else if(i%10==1)
            cube(0.5,0.5,0.5);
        else if(i%10==1)
            cube(0.8,0,0);
        else
            cube(0.2,0.5,0.7);
        glPopMatrix();
        rr+=1;
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }


}
