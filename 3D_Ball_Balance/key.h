int up=0,down=0,r=0,l=0,f=0,b=0;
int m_rot = 0;

GLfloat eye[] = {0,40,50};
GLfloat look[] = {0,40,-100};

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    //for light
    case '1':
        light_1 = !light_1;
        break;
    case '2':
        light_2 = !light_2;
        break;
    case '3':
        light_3 = !light_3;
        break;

    //fan

    case 't':
        eye[1]++;
        look[1]++;
        break;
    case 'g':
        eye[1]--;
        look[1]--;
        break;
    case 'h':
        look[0]++;
        break;
    case 'f':
        look[0]--;
        break;
    case 'q':
        ar = 0.1, ag = 0.1, ab = 0.1;
        dr = 1, dg =1, db =1;
        sr = 1, sg =1, sb =1;
        break;
    case 'a':
        flr_move = false;
        ball_x_pos -= 2*(60/2*sin((inc*3.1416)/180));
        //ball_y_pos -= (60/2*sin((inc*3.1416)/180));
        //glRotatef(ball_rot,ball_rot_x,ball_rot_y,ball_rot_z);
        break;
    case 'd':
        flr_move = false;
        ball_x_pos -= (60/2*sin((inc*3.1416)/180));
        //ball_y_pos += (60/2*sin((inc*3.1416)/180));
        break;
    case 'e':
        m_rot--;
        break;
    case 'r':
        m_rot++;
        break;
    case 'l':
        if(r<=36)
        {
            r++;
            l--;
            eye[0]++;
            look[0]++;
        }
        break;
    case 'j':
        if(l<=36)
        {
            r--;
            l++;
            eye[0]--;
            look[0]--;
        }

        break;
    case '+':
        eye[2]--;
        break;
    case 'i':
        if(f<=80)
        {
            f++;
            b--;
            eye[2]--;
        }

        break;
    case '-':
        eye[2]++;
        break;
    case 'k':
        if(b<1)
        {
            b++;
            f--;
            eye[2]++;
        }

        break;

    }

    glutPostRedisplay();
}
