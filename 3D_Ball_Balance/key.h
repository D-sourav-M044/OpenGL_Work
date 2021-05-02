int up=0,down=0,r=0,l=0,f=0,b=0;
int m_rot = 0;

GLfloat eye[] = {0,50,75};
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
    case 'w':
        ball_pos_z -=1;
        break;
    case 's':
        ball_pos_z +=1;
        break;
    case 'a':

        if(ok && flag)
        {
            flr_move = !flr_move;
            int t = 6;
            if(inc>=0)
                ball_pos_x -= t*(surface_len/2*sin((inc*3.1416)/180));
            else
                ball_pos_x += t*(surface_len/2*sin((inc*3.1416)/180));
            ball_rot += inc;
            ball_rot_z = 1;
        }
        else
            ball_pos_x-=1;

        break;
    case 'd':
        if(ok && flag)
        {
            flr_move = !flr_move;
            int t = 6;
            if(inc>=0)
                ball_pos_x += t*(surface_len/2*sin((inc*3.1416)/180));
            else
                ball_pos_x -= t*(surface_len/2*sin((inc*3.1416)/180));

            ball_rot += inc;
            ball_rot_z = 1;
        }
        else
            ball_pos_x+=1;
        break;
    case 'e':
        m_rot--;
        break;
    case 'r':
        m_rot++;
        break;
    case 'l':
            eye[0]++;
            look[0]++;
        break;
    case 'j':
            eye[0]--;
            look[0]--;
        break;
    case '+':
        eye[2]--;
        break;
    case 'i':
            eye[2]--;


        break;
    case '-':
        eye[2]++;
        break;
    case 'k':
            eye[2]++;
        break;


    }

    glutPostRedisplay();
}
