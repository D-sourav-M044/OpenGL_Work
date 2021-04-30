int type = 1;
void drawText(const char *text,int length, int x, int y)
{
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX,matrix);
    glLoadIdentity();
    glOrtho(0,800,0,600,-5,5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    if(1)
    {
        for(int i=0; i<length; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)text[i]);
    }
    }
//    else
//    {
//            {
//        for(int i=0; i<length; i++)
//    {
//        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
//    }
//
//    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}
