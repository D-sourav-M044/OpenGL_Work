int up=0,down=0,r=0,l=0,f=0,b=0;
int m_rot = 0;

//GLfloat eye[] = {0,50,175};
//GLfloat look[] = {0,50,-100};

//GLfloat eye[] = {250,50,80};
//GLfloat look[] = {250,50,-100};

//GLfloat eye[] = {ball_pos_x,50,ball_pos_z+50};
//GLfloat look[] = {ball_pos_x,50,-200};

GLfloat eye[] = {0,10,30};
GLfloat look[] = {0,10,-100};

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
    case '4':
        light_4 = !light_4;
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
    case 'w':
        eye[2] = ball_pos_z+50;

        ball_int_rot -= 10;
        ball_int_rot_x = 1;
        ball_pos_z -=1;

        if(ball_speed_in)
        {
            cout<<" ball_speed "<< ball_speed<<endl;
            ball_speed +=2;
        }

        break;
    case 's':
        eye[2] = ball_pos_z+50;

        ball_int_rot += 10;
        ball_int_rot_x = 1;
        ball_pos_z +=1;
        break;
    case 'a':
        eye[0] = ball_pos_x;
        look[0] = ball_pos_x;
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
        {
            ball_int_rot += 10;
            ball_int_rot_z = 1;
            ball_pos_x -=1;
        }

        break;
    case 'd':
        eye[0] = ball_pos_x;
        look[0] = ball_pos_x;
//
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
        {
            ball_int_rot -= 10;
            ball_int_rot_z = 1;
            ball_pos_x+=1;
        }

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
        look[2]--;
        break;
    case 'i':
        eye[2]--;
        look[2]--;
        break;
    case '-':
        eye[2]++;
        look[2]++;
        break;
    case 'k':
        eye[2]++;
        look[2]++;
        break;
    case 'n':
        ball_fall = 0;
        ball_fall_rot = 0;
        ball_fall_y = 0;
        ball_rot = 0;
        ball_fall_rot_z = 0;
        //cout<<"restore"<<endl;
        ball_pos_x = ball_st_pos_x;
        ball_pos_y = ball_st_pos_y;
        ball_pos_z = ball_st_pos_z;
        break;
    case 'p':
        lig_4_pos +=5;
        break;
    case ' ':
    ball_jump_cond = true;
        break;

    }


    glutPostRedisplay();
}
