bool light_1 = false, light_2 = false, light_3 = false, light_4 = false, fan_on = false;
float ar = 0.1, ag = 0.1, ab = 0.1, dr = 1, dg = 1, db = 1, sr = 1, sg = 1, sb = 1;

void point_light_effect(int light_no = 1,float x = 0, float y = 20, float z = 0, float R = 1, float G = 1, float B = 1)
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat light_ambient[]  = {R, G, B, 0.0};
//    GLfloat light_diffuse[]  = { R, G, B, 1.0 };
//    GLfloat light_specular[] = { 1,1,1, 1.0 };
GLfloat light_ambient[]  = {0.1,0.1,0.1, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { x,y,z, 1.0 };

    if(light_no == 1)
    {
        glEnable( GL_LIGHT1);

        if(light_1)
        {
            glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
            glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
            glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
        }
        else
        {
            glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);
            glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);
            glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);

        }
        glLightfv( GL_LIGHT1, GL_POSITION, light_position);
    }

    else if(light_no == 2)
    {
        glEnable( GL_LIGHT2);

        if(light_2)
        {
            glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient);
            glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse);
            glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular);
        }
        else
        {
            glLightfv( GL_LIGHT2, GL_AMBIENT, no_light);
            glLightfv( GL_LIGHT2, GL_DIFFUSE, no_light);
            glLightfv( GL_LIGHT2, GL_SPECULAR, no_light);
        }
        glLightfv( GL_LIGHT2, GL_POSITION, light_position);
    }


}

void extra_light()
{
    //GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.1,0.1,0.1, 1.0};
    GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat light_diffuse[]  = { 0.1, 0.1, 0.1, 1.0 };
//    GLfloat light_specular[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat light_position[] = { 0.0, 20.0, 0.0, 1.0 };

    glEnable( GL_LIGHT7);

    glLightfv( GL_LIGHT7, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT7, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT7, GL_SPECULAR, light_specular);

    glLightfv( GL_LIGHT7, GL_POSITION, light_position);


    /*GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0);*/
}


void spot_light_effect(float x, float y, float z, float cut_off = 25.0, float R=1, float G=1, float B=1)
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {R, G, B, 0.0};
    GLfloat light_diffuse[]  = { R,G,B, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { x,y,z, 1.0 };
    glEnable( GL_LIGHT3);

    if(light_3)
    {
        glLightfv( GL_LIGHT3, GL_AMBIENT, light_ambient);
        glLightfv( GL_LIGHT3, GL_DIFFUSE, light_diffuse);
        glLightfv( GL_LIGHT3, GL_SPECULAR, light_specular);
    }
    else
    {
        glLightfv( GL_LIGHT3, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT3, GL_DIFFUSE, no_light);
        glLightfv( GL_LIGHT3, GL_SPECULAR, no_light);

    }
    glLightfv( GL_LIGHT3, GL_POSITION, light_position);

    GLfloat light_direction[] = {0,0,1,1};
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_direction);
    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, cut_off);
}

void torch_spot_light(float x, float y, float z, float cut_off = 5.0, float R=1, float G=0.6, float B=0.4)
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {R, G, B, 0.0};
    GLfloat light_diffuse[]  = { R,G,B, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { x,y,z, 1.0 };
    glEnable( GL_LIGHT4);

    if(light_4)
    {
        glLightfv( GL_LIGHT4, GL_AMBIENT, light_ambient);
        glLightfv( GL_LIGHT4, GL_DIFFUSE, light_diffuse);
        glLightfv( GL_LIGHT4, GL_SPECULAR, light_specular);
    }
    else
    {
        glLightfv( GL_LIGHT4, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT4, GL_DIFFUSE, no_light);
        glLightfv( GL_LIGHT4, GL_SPECULAR, no_light);

    }
    glLightfv( GL_LIGHT4, GL_POSITION, light_position);

    GLfloat light_direction[] = {0,-1,0,1};
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light_direction);
    glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, cut_off);
}

