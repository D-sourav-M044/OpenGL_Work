
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int lim = 8;
    glFrustum(-lim, lim, -lim, lim, 4, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    gluLookAt(eye[0],eye[1],eye[2], look[0],look[1],look[2], 0,1,0);



    glRotatef(m_rot,0,1,0);
    //extra_light();
    //axes();

    //ball
    glPushMatrix();
    glRotatef(ball_rot,ball_rot_x,ball_rot_y,ball_rot_z);
    ball();
    glPopMatrix();


////up_down_flr
    glPushMatrix();
    up_down_flr();
    glPopMatrix();

//moving
    glPushMatrix();
    floor();
    glPopMatrix();



//starting flr
    glPushMatrix();
    normal_flr();
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 1);

water_flr();
back_side();
side_wall();


    //glDisable(GL_TEXTURE_2D);

    glFlush();
    glutSwapBuffers();
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

