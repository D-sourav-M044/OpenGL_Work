
float w_flow = 0, w_flow_var = 0.8;
void water_flow()
{
    w_flow += w_flow_var;
    if(w_flow<=-200)
        w_flow_var = 0.8;
    else if(w_flow>=200)
        w_flow_var = -0.8;
    glutPostRedisplay();
}

float ter_cir_pi_rot =0, ter_cir_pi_rot_var = 0.2;
void ter_cir_pi_rot_cal()
{
    ter_cir_pi_rot += ter_cir_pi_rot_var;
    glutPostRedisplay();
}
void water_terbine();

void water_flr(float water_flr_len = 2500, float water_flr_height = 30, float water_flr_width = 1000)
{
    float plot_len = 200, plot_width = 40;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 8);

//    for(float i=-water_flr_width/2; i<=water_flr_width/2; i+=plot_width)
//    {
//        for(float j = -water_flr_len/2; j<= water_flr_len/2; j+= plot_len)
//        {
//            glPushMatrix();
//            glTranslatef(w_flow,0,-water_flr_width/2);
//            glTranslatef(j,-200,i);
//            glScalef(plot_len,water_flr_height,plot_width);
//            glTranslatef(-0.5,-0.5,-0.5);
//            cube(0,0,0.5,0,1);
//            water_flow();
//            glPopMatrix();
//        }
//    }

    glPushMatrix();
    glTranslatef(w_flow,0,0);
    glTranslatef(0,-200,0);
    glScalef(water_flr_len,water_flr_height,water_flr_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0,0,1,0,1);
    water_flow();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(-400,-100,-400);
    water_terbine();
    glPopMatrix();

}


void water_terbine()
{

    //water terbine

    //middle bar
    glPushMatrix();
    glScalef(5,5,30);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,0,0,0,1);
    glPopMatrix();

    //stand
    for(float i= -30; i<=30; i+=60)
    {
        for(float z = -10; z<=10; z+=20)
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, 4);

            glPushMatrix();
            glRotatef(i,0,0,1);
            glTranslatef(0,-200,z);
            glScalef(20,400,2);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.5,0.3,0.4,0,1);
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);
        }


    }

    glPushMatrix();
    glRotatef(ter_cir_pi_rot,0,0,1);

    //circle
    glPushMatrix();
    torus(0.5,0.4,0.3,5,100);
    //torus(0.3,0.4,0.2,5,80);
    torus(0.5,0.5,0.4,5,60);
    glPopMatrix();



    //stick in circle
    for(float i=0; i<=360.0; i+=22.5)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,3);

        glPushMatrix();
        glRotatef(i,0,0,1);
        glTranslatef(50,0,0);
        glScalef(100,5,5);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(1,1,1,0,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }

    //bar
    for(float i=0; i<=360.0; i+=11.25)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,3);

        glPushMatrix();
        glRotatef(i,0,0,1);
        glTranslatef(120,0,0);
        glScalef(40,5,5);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(1,0.5,0.5,0,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }

    ter_cir_pi_rot_cal();
    glPopMatrix();

}
