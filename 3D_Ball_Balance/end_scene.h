

void end_scene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();

    //text -1
    glColor3f(1,0,0);
    glRasterPos3f(-0.3,0.5,0);

    char msg[] = "------------Congratulaitions---------";
    for(int i=0; i<strlen(msg); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);

    //Text-2
    glColor3f(1,1,1);
    glRasterPos3f(-0.2,0.2,0);
    char msg2[] = "you have successfully completed the task";
    for(int i=0; i<strlen(msg2); i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,msg2[i]);

    //text-3
    glColor3f(1,1,0);
    glRasterPos3f(-0.1,0.1,0);
    double sp_time = double(end_time-st_time);
    ostringstream ss_min, ss_sec;
    string str_min, str_sec;
    string s = "total time : ";

    if(sp_time>60)
    {
//        double sp_min = sp_time/60;
//        double sp_sec = sp_time - 60*sp_min;
//        ss_min<<sp_time;
//        ss_sec<<sp_sec;
//        str_min = ss_min.str();
//        str_sec = ss_sec.str();
//
//        s += str_min;
//        s += " min ";
//        s += str_sec;
//        s += " sec";

        int sp_min = int(sp_time/60);
        int sp_sec = int(sp_time - 60*sp_min);
        ss_min << sp_min;
        ss_sec << sp_sec;

         str_min = ss_min.str();
        str_sec = ss_sec.str();

        s += str_min;
        s += " min ";
        s += str_sec;
        s += " sec";



    }
    else
    {
        ss_sec << sp_time;
        str_sec = ss_sec.str();

        s += str_sec;
        s += " sec ";
    }


    for(int i=0; i<s.size(); i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s[i]);







//glFlush();

    glutSwapBuffers();


}
