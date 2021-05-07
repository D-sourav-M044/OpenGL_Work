
float w_flow = 0, w_flow_var = 0.002;
void water_flow()
{
    w_flow += w_flow_var;
    if(w_flow<=-40)
        w_flow_var = 0.002;
    else if(w_flow>=40)
        w_flow_var = -0.002;
    glutPostRedisplay();
}


void water_flr(float water_flr_len = 1500, float water_flr_height = 30, float water_flr_width = 500)
{
    float plot_len = 200, plot_width = 40;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 8);

    for(float i=-water_flr_width/2; i<=water_flr_width/2; i+=plot_width)
    {
        for(float j = -water_flr_len/2; j<= water_flr_len/2; j+= plot_len)
        {
            glPushMatrix();
            glTranslatef(w_flow,0,-water_flr_width/2);
            glTranslatef(j,-200,i);
            glScalef(plot_len,water_flr_height,plot_width);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(1,1,1,0,1);
            water_flow();
            glPopMatrix();
        }
    }


    glDisable(GL_TEXTURE_2D);
}
