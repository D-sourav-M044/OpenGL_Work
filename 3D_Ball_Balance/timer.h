double game_timer = 0;
bool timer_in = true;

void timer_inc(int val)
{
    game_timer +=val;
    timer_in = true;
}


void timer_inc_detect()
{
    if(timer_in)
    {
        timer_in = false;
        glutTimerFunc(1000,timer_inc,1);
    }
}

void timer()
{

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(4.0);
    obj_mat(1,1,0);

    glPushMatrix();
    glTranslatef(ball_pos_x-50,7,ball_pos_z+20);
    glScalef(0.02,0.02,0.01);
    ostringstream ss_min, ss_sec;
    string str_min, str_sec;
    string s = "total time : ";
    if(game_timer<60)
    {
        ss_sec << game_timer;
        str_sec = ss_sec.str();

        s += str_sec;
        s += " sec ";
    }
    else
    {
        int sp_min = int(game_timer/60);
        int sp_sec = int(game_timer - 60*sp_min);

        ss_min << sp_min;
        ss_sec << sp_sec;

        str_min = ss_min.str();
        str_sec = ss_sec.str();

        s += str_min;
        s += " min ";
        s += str_sec;
        s += " sec";

    }


    for(int i=0; i<s.size(); i++)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,s[i]);
    timer_inc_detect();
    glPopMatrix();




}


