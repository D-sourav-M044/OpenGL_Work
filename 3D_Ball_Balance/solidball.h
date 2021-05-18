float sphere_up = 8;
static GLfloat v_ball[800][3];
static GLfloat v_top[1600][3];
static bool v_ball_load = false;
static bool v_top_load = false;

void ball_ind_point_load(float r)
{
    if(!v_ball_load)
    {
        v_ball_load = !v_ball_load;

        bool sl_flag = false;
        int num_segments = 80;
        float cx, cy;
        GLfloat y = 0;

//        float y_inc = slice;
//        float circle_radius = 0 ;
        int cir = 0;
        for(int seg = 0; seg <1600 ; seg+=20)
        {
            int ii = 0;
            float circle_radius = sqrt(r*r-(r-cir)*(r-cir));
            for(int ind =seg; ind<seg+20 ; ind++)
            {
                float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
                GLfloat x = circle_radius * cosf(theta);//calculate the x component
                GLfloat z = circle_radius * sinf(theta);//calculate the y component
                v_ball [ind][0] = x;
                v_ball [ind][1] = y;
                v_ball [ind][2] = z;


                ii+=4;
            }


            if(circle_radius >= r)
                sl_flag = true;
            if(sl_flag)
            {
                //circle_radius -= slice;
                cir--;
                y =(r+(r-cir));
                //y +=1;
                //cout<<y<<endl;
            }

            else
            {
                //circle_radius += slice;
                cir++;
                y = cir;
                //y += 1;
            }

        }
    }
}
void v_top_point_load(float r)
{
    if(!v_top_load)
    {
        v_top_load = !v_top_load;

        bool sl_flag = false;
        int num_segments = 80;
        float cx, cy;
        GLfloat y = 0;

        float slice = r/20;
        float y_inc = slice;
        float circle_radius = slice ;
        for(int seg = 0; seg <1600 ; seg+=20)
        {
            int ii = 0;

            for(int ind =seg; ind<seg+20 ; ind++)
            {
                float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
                GLfloat x = circle_radius * cosf(theta);//calculate the x component
                GLfloat z = circle_radius * sinf(theta);//calculate the y component
                v_top [ind][0] = x;
                v_top [ind][1] = y;
                v_top [ind][2] = z;


                ii+=4;
            }


            if(circle_radius >= r)
                sl_flag = true;
            if(sl_flag)
            {
                circle_radius -= slice;

                //cout<<y<<endl;
            }

            else
            {
                circle_radius += slice;
            }
            y+=slice;

        }
    }
}
void obj_mat(float R, float G, float B)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { R, G, B, 1.0 };
    GLfloat mat_diffuse[] = { R, G, B, 1.0 };
    GLfloat mat_specular[] = { 0.5,0.5,0.5, 1.0 };
    GLfloat mat_emission[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {30};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    //glMaterialfv ( GL_FRONT, GL_EMISSION, mat_emission);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
}

void drawball(float r)
{

ball_ind_point_load(r);

    glPushMatrix();
    glTranslatef(0,-r,0);



//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D,6);

    bool ball_col_flag = 1;
    glBegin(GL_QUADS);
    for(int i=0; i<320; i++)
    {
        if(ball_col_flag)
        {
            obj_mat(0,1,1);
            ball_col_flag = !ball_col_flag;
        }

        else
        {
            obj_mat(0,0,0);
            ball_col_flag = !ball_col_flag;
        }
        if(i%20==19)
            ball_col_flag = !ball_col_flag;

        if(i%20==19)
        {
            getNormal3p(v_ball[i][0], v_ball[i][1], v_ball[i][2],
                    v_ball[i-19][0], v_ball[i-19][1], v_ball[i-19][2],
                    v_ball[i+1][0], v_ball[i+1][1], v_ball[i+1][2]);
//            getNormal3p(v_ball[i+1][0], v_ball[i+1][1], v_ball[i+1][2],
//                    v_ball[i-19][0], v_ball[i-19][1], v_ball[i-19][2],
//                    v_ball[i][0], v_ball[i][1], v_ball[i][2]);

            glTexCoord2f(0,0);
            glVertex3fv(&v_ball[i][0]);
            glTexCoord2f(0,1);
            glVertex3fv(&v_ball[i-19][0]);
            glTexCoord2f(1,1);
            glVertex3fv(&v_ball[i+1][0]);
            glTexCoord2f(1,0);
            glVertex3fv(&v_ball[i+20][0]);
        }
        else
        {
            getNormal3p(v_ball[i][0], v_ball[i][1], v_ball[i][2],
                    v_ball[i+1][0], v_ball[i+1][1], v_ball[i+1][2],
                    v_ball[i+21][0], v_ball[i+21][1], v_ball[i+21][2]);
//            getNormal3p(v_ball[i+21][0], v_ball[i+21][1], v_ball[i+21][2],
//                    v_ball[i+1][0], v_ball[i+1][1], v_ball[i+1][2],
//                    v_ball[i][0], v_ball[i][1], v_ball[i][2]);


            glTexCoord2f(0,0);
            glVertex3fv(&v_ball[i][0]);
            glTexCoord2f(0,1);
            glVertex3fv(&v_ball[i+1][0]);
            glTexCoord2f(1,1);
            glVertex3fv(&v_ball[i+21][0]);
            glTexCoord2f(1,0);
            glVertex3fv(&v_ball[i+20][0]);
        }

    }
    glEnd();

    //glDisable(GL_TEXTURE_2D);



}

void torch_top(float r=7)
{
    v_top_point_load(r);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);

    glBegin(GL_QUADS);
    for(int i=0; i<400; i++)
    {
        if(i%2)
            obj_mat(1,1,1);
        else
            obj_mat(1,0,0);
        glTexCoord2f(0,0);
        glVertex3fv(&v_top[i][0]);
        glTexCoord2f(0,1);
        glVertex3fv(&v_top[i+1][0]);
        glTexCoord2f(1,1);
        glVertex3fv(&v_top[i+21][0]);
        glTexCoord2f(1,0);
        glVertex3fv(&v_top[i+20][0]);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}


void ball_try()
{
    float ball_radi = 8;

//    for(float ball_radi =0.1; ball_radi<=8; ball_radi += 0.1)
//    {
    float ball_rot = 0;
    glPushMatrix();
    glTranslatef(0,ball_radi+0.1,0);
    for(int i=0; i<100; i++)
    {
        glPushMatrix();

        glRotatef(ball_rot,0,0,1);
        glTranslatef(ball_radi,0,0);
        glScalef(ball_radi,1,ball_radi);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();
        ball_rot +=5;
    }
    glPopMatrix();
//    }

}
