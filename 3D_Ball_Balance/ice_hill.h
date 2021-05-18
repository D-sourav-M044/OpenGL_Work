float ice_var = 0, ice_ind=0.51;
void ice_hill_rot()
{
    ice_var += ice_ind;
    if(ice_var>=50)
        ice_ind = -0.5;
    if(ice_var<=-200)
        ice_var = 0;

    glutPostRedisplay();
}

float ice_var_ = 0, ice_ind_=0.5;
void ice_hill_rot_()
{
    ice_var_ += ice_ind_;
    if(ice_var_>=200)
        ice_ind_ = -0.5;
    if(ice_var_<=-150)
        ice_var_ = 0;

    glutPostRedisplay();
}
void ice_hill()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,19);

    glPushMatrix();
    glTranslatef(0,-200+ice_var,-500);
    //glRotatef(ice_var,1,0,0);
    glScalef(400,700,100);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    ice_hill_rot();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);


    //2
     glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,19);

    glPushMatrix();
    glTranslatef(0,-250+ice_var_/2,-500);
    //glRotatef(ice_var,1,0,0);
    glScalef(400,700,100);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    ice_hill_rot_();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //fixed
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,19);

    glPushMatrix();
    glTranslatef(200,0,-500);
    glScalef(2000,700,50);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
