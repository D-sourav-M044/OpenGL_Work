
void thunder_effect()
{
    int d = 2;
    for(int i=0;i<=10;i++)
    {
        glPushMatrix();
        glRotatef(i,0,0,1);
        glTranslatef(0,d+10,0);
        glScalef(1,1,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();
        d+=2;
    }

}
