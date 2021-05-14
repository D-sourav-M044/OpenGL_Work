
//float fire_rot_angle = 0,fire_rot_angle_var=0.0001;
//void fire_animation()
//{
//    fire_rot_angle += fire_rot_angle_var;
//    if(fire_rot_angle>=0.25)
//        fire_rot_angle_var = -0.0001;
//    if(fire_rot_angle<=-0.25)
//        fire_rot_angle_var = 0.0001;
//    glutPostRedisplay();
//}
float con_rot = 0;

float fire_rot_angle = 0,fire_rot_angle_var=0.01;
void fire_animation()
{
    fire_rot_angle += fire_rot_angle_var;
    if(fire_rot_angle>=25)
        fire_rot_angle_var = -0.01;
    if(fire_rot_angle<=-25)
        fire_rot_angle_var = 0.01;
    glutPostRedisplay();
}

float fire_y = 0, fire_y_var = 0.0001;
void fire_y_cal()
{
    fire_y += fire_y_var;
    if(fire_y >=3)
        fire_y = 0;
    glutPostRedisplay();
}
void torch()
{
    //handle
    float t_hangle_rot = 0;

    glPushMatrix();
    //glTranslatef(-200,-200,-300);

    for(int i=0; i<100; i++)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,1);

        glPushMatrix();
        glRotatef(t_hangle_rot,0,1,0);
        glTranslatef(0,-50,0);
        glScalef(10,200,10);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(1,0,1,1,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
        t_hangle_rot++;
    }

    //top
    glPushMatrix();
    glTranslatef(0,30,0);
    torch_top(20);
    //spot_light_effect(1,0,30,0,1,1,0);
    glPopMatrix();

    //kuet logo
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,18);
    glPushMatrix();
    glTranslatef(0,20,0);
    glScalef(15,15,15);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0,0.5,0,light_4);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    //point -light-1
    glPushMatrix();
    point_light_effect(1,0,70,0);
    glPopMatrix();

    //top-right-curve
    glPushMatrix();
    glTranslatef(8,50,0);
    glRotatef(-90,0,0,1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    float top_curve_rot = 0;
    for(int i=0; i<=50; i++)
    {
        glPushMatrix();

        glRotatef(top_curve_rot,0,0,1);
        glTranslatef(50,0,0);
        glScalef(1,5,25);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0,0.5,0);
        glPopMatrix();

        top_curve_rot +=3;
    }
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //top left curve
    glPushMatrix();
    glTranslatef(-8,50,0);
    glRotatef(-60,0,0,1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    float top_curve_rotr = 0;
    for(int i=0; i<=50; i++)
    {
        glPushMatrix();

        glRotatef(-top_curve_rotr,0,0,1);
        glTranslatef(-50,0,0);
        glScalef(1,5,25);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0,0);
        glPopMatrix();

        top_curve_rotr -=3;
    }
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //top back curve
    glPushMatrix();
    glTranslatef(0,30,0);
    glRotatef(-90,0,1,0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    float top_curve_rotu = 0;
    for(int i=0; i<=50; i++)
    {
        glPushMatrix();

        glRotatef(-top_curve_rotu,0,0,1);
        glTranslatef(-50,0,0);
        glScalef(10,5,25);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(1,1,1);
        glPopMatrix();

        top_curve_rotu +=2.5;
    }
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //fire
    bool fire_rot_flag = true;
    for(int pos = 12; pos<=20; pos+=10)
    {
        for(float i=1; i<19; i+=1)
        {
            for(float j=0; j<15; j+=1)
            {

                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D,15);

                glPushMatrix();
                glTranslatef(fire_rot_angle/100,0,0);
                glRotatef(fire_rot_angle/10,0,1,0);

                glPushMatrix();
                glTranslatef(0,-pos,0);
                glTranslatef(i,fire_y,j);
                glTranslatef(-10,60.5,-5);
                glScaled(0.5,10,0.5);
                glTranslatef(-0.5,-0.5,-0.5);
                cube(0,0,1,1,1);
                fire_y_cal();
                glPopMatrix();

                fire_animation();
                glPopMatrix();

                glDisable(GL_TEXTURE_2D);
            }

        }

    }

    glPopMatrix();


}
