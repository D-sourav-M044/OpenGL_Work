float rain_fall_down = 0, rain_fall_down_d = 0.0001;


void rain_fall_cal()
{
    rain_fall_down += rain_fall_down_d;
    if(rain_fall_down >= 50)
        rain_fall_down = 0;
    glutPostRedisplay();
}
void rain_fall()
{
    float area_len = 1500, area_width = 500;
    float rain_len = 0.1, rain_height = 5, rain_width = 0.1;
    for(int f = 500; f>=0; f -= 50)
    {
        for(int i= -(area_width/2-200); i<=area_width/2-100; i+=20)
        {
            for(int j= -(area_len/2-200); j<= area_len/2-200; j+=20)
            {
                glPushMatrix();
                glRotatef(5,0,0,1);
                glTranslatef(0,f,0);
                glTranslatef(j,-rain_fall_down,i);
                glScalef(rain_len, rain_height, rain_width);
                glTranslatef(-0.5,-0.5,-0.5);
                cube();
                rain_fall_cal();
                glPopMatrix();
            }
        }
}



//    for(int i= -area_width/2; i<=area_width/2; i+=10)
//    {
//        for(int j= -area_len/2; j<= area_len/2; j+=10)
//        {
//            glPushMatrix();
//            glTranslatef(0,450,0);
//            glTranslatef(j,-rain_fall_down,i);
//            glScalef(rain_len, rain_height, rain_width);
//            glTranslatef(-0.5,-0.5,-0.5);
//            cube(1,1,1,1);
//            rain_fall_cal();
//            glPopMatrix();
//        }
//    }
//
//
//    for(int i= -area_width/2; i<=area_width/2; i+=10)
//    {
//        for(int j= -area_len/2; j<= area_len/2; j+=10)
//        {
//            glPushMatrix();
//            glTranslatef(0,400,0);
//            glTranslatef(j,-rain_fall_down,i);
//            glScalef(rain_len, rain_height, rain_width);
//            glTranslatef(-0.5,-0.5,-0.5);
//            cube(1,1,1,1);
//            rain_fall_cal();
//            glPopMatrix();
//        }
//    }


}
