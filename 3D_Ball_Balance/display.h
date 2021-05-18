
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int lim = 8;
    cout<<end_scen_enable<<endl;
    if(end_scen_enable)
    {
        time(&end_time);
        glutDisplayFunc(end_scene);
    }
    if(!end_scen_enable)
    {
        glFrustum(-lim, lim, -6, 6, 4, 1000);
        //cout<<end_scen_enable<<endl;
    }
//
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    if(!starting_view_animation_x && !starting_view_animation_z && !end_scen_enable)
    {
        gluLookAt(eye[0],eye[1],eye[2], look[0],look[1],look[2], 0,1,0);
        //cout<<"eye_check"<<endl;
        //rain_fall();
    }

//    else
//     gluLookAt(eye_ani[0],eye_ani[1],eye_ani[2], look_ani[0],look_ani[1],look_ani[2], 0,1,0);



    //glRotatef(m_rot,0,1,0);

//score_board();
//    glPushMatrix();
//    glTranslatef(400,0,-200);
//    axes();
//    glPopMatrix();
////
    // ball
    glPushMatrix();
    glRotatef(ball_rot,ball_rot_x,ball_rot_y,ball_rot_z);
    ball();
    glPopMatrix();
//
//
////up_down_flr
    up_down_flr();
//
//moving
    floor();
////
//////starting
    normal_flr();
//////
////////
    short_way();
    road();

    water_flr();
    back_side();
    front_side();
    left_side_wall();
//rain_fall();
//thunder_effect();
//
    glPushMatrix();
    glTranslatef(0,-50,-100);
    glScalef(2,2,2);
    torch();
    glPopMatrix();

    moving_flr();
//
    search_light_house();
    ice_hill();
//
    //starting_view();

    finishing_flr();
//end_scene();

    //drawball(8);

    glFlush();
    if(!end_scen_enable)
    {
        glutSwapBuffers();
    }

}

void welcomedisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //text -1
    glColor3f(1,0,0);
    glRasterPos3f(-0.3,0.5,0);

    char msg[] = "------------3D_Ball_Balance---------";
    for(int i=0; i<strlen(msg); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);

    //Text-2
    glColor3f(1,1,1);
    glRasterPos3f(0,0.2,0);
    char msg2[] = "Presented By:";
    for(int i=0; i<strlen(msg2); i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,msg2[i]);

    //text-3
    glColor3f(1,1,1);
    glRasterPos3f(0,0.1,0);
    char msg3[] = "Sourav M Dipto";
    for(int i=0; i<strlen(msg3); i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,msg3[i]);

    //text-4
    glColor3f(1,1,1);
    glRasterPos3f(0,0,0);
    char msg4[] = "CSE, KUET";
    for(int i=0; i<strlen(msg4); i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,msg4[i]);

    //text-5
    glColor3f(0.5,1,0.5);
    glRasterPos3f(-0.2,-0.5,0);
    char msg5[] = "Game Is Getting Ready, Please Wait...........";
    for(int i=0; i<strlen(msg5); i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,msg5[i]);




    glutSwapBuffers();
}

void myTimer (int val)
{

    glutDisplayFunc(display);
    extra_light();
    glEnable(GL_LIGHTING);
    glutPostRedisplay();
}

