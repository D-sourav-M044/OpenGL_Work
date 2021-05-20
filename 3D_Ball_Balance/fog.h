bool fog_on = true;
float fog_den = 0.0001;
void fog_den_inc()
{
    if(fog_den<0.002)
    fog_den += 0.000005;
    else if(fog_den<0.003)
        fog_den += 0.0000005;
}
void fog()
{
    glPushMatrix();
    GLfloat density = fog_den;

    GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};

    glEnable (GL_FOG); //enable the fog

    glFogi (GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2

    glFogfv (GL_FOG_COLOR, fogColor); //set the fog color to
    //our color chosen above

    glFogf (GL_FOG_DENSITY, density); //set the density to the
    //value above

    //glHint (GL_FOG_HINT, GL_NICEST); // set the fog to look the
    //nicest, may slow down on older cards

    fog_den_inc();
    glPopMatrix();
}

