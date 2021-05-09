
static GLfloat v_ball[1600][3];
static bool v_ball_load = false;

void ball_ind_point_load(float r)
{
    if(!v_ball_load)
    {
        v_ball_load = !v_ball_load;

        bool sl_flag = false;
        int num_segments = 80;
        float cx, cy;
        GLfloat y = 0;
        float slice = r/40;
        float y_inc = r/10;
        float circle_radius = 0 ;

        for(int seg = 0; seg <1600 ; seg+=20)
        {
            int ii = 1;

            for(int ind =seg; ind<seg+20 ; ind++)
            {
                float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
                GLfloat x = circle_radius * cosf(theta);//calculate the x component
                GLfloat z = circle_radius * sinf(theta);//calculate the y component
                glColor3f(1,0,0);
                v_ball [ind][0] = x;
                v_ball [ind][1] = y;
                v_ball [ind][2] = z;


                ii+=4;
            }
            y += slice;
            if(circle_radius >= r)
                sl_flag = true;
            if(sl_flag)
                circle_radius -= slice;
            else
                circle_radius += slice;

        }
    }
}

void obj_mat(float R, float G, float B)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { R, G, B, 1.0 };
    GLfloat mat_diffuse[] = { R, G, B, 1.0 };
    GLfloat mat_specular[] = { 1,1,1, 1.0 };
     GLfloat mat_emission[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {30};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv ( GL_FRONT, GL_EMISSION, mat_emission);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
}

void drawball(float r)
{
//    float R = 0.1,G=0.8,B =0.2;



    ball_ind_point_load(r);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,7);

    obj_mat(1,0,0);
    glBegin(GL_QUADS);
    for(int i=0; i<1580; i++)
    {
        if(i%2)
            obj_mat(1,1,1);
        else
            obj_mat(1,0,0);
        glTexCoord2f(0,0);
        glVertex3fv(&v_ball[i][0]);
        glTexCoord2f(0,1);
        glVertex3fv(&v_ball[i+1][0]);
        glTexCoord2f(1,1);
        glVertex3fv(&v_ball[i+21][0]);
        glTexCoord2f(1,0);
        glVertex3fv(&v_ball[i+20][0]);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);


}

//void torus()
//{
//    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
//    GLfloat mat_ambient[] = { 0.5, 0.0, 0.0, 1.0 };
//    GLfloat mat_diffuse[] = { 0.5, 0.0, 0.0, 1.0 };
//    GLfloat mat_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_specular[] = { 1, 1, 0, 1.0 };
//    GLfloat mat_shininess[] = {30};
//
//    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
//    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//
//    glPushMatrix();
//    glutSolidSphere(8,20,16);
//    glutSolidTorus(0.5,5,16,16);
//    glPopMatrix();
//}

void c_ball()
{
    glPushMatrix();
    glutSolidSphere(5,16,16);
    torus();
    glPopMatrix();
}

