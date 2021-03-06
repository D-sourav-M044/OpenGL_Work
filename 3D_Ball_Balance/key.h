int up=0,down=0,r=0,l=0,f=0,b=0;
int m_rot = 0;

//GLfloat eye[] = {0,50,180};
//GLfloat look[] = {0,50,-1000};

//GLfloat eye[] = {350,50,-150};
//GLfloat look[] = {350,50,-1000};

GLfloat eye[] = {ball_pos_x,50,ball_pos_z+50};
GLfloat look[] = {ball_pos_x,50,-200};


GLfloat lasteye[] = {0,50,180};
GLfloat lastlook[] = {0,50,-200};


GLfloat eye_ani[] = {600,150,-100};
GLfloat look_ani[] = {0,80,-100};


bool end_scene_status = true;

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    //for light
    case '0':
        ex_light = !ex_light;
        break;
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
    //light property
    //ambient
    case ',':
        ar+=0.05;
        ag+=0.05;
        ab+=0.05;
        break;
    case '<':
        ar-=0.05;
        ag-=0.05;
        ab-=0.05;
        break;
    //diffuse
    case '.':
        dr+=0.05;
        dg+=0.05;
        db+=0.05;
        break;
    case '>':
        dr-=0.05;
        dg-=0.05;
        db-=0.05;
        break;
    //specular
    case '/':
        sr+=0.05;
        sg+=0.05;
        sb+=0.05;
        break;
    case '?':
        sr-=0.05;
        sg-=0.05;
        sb-=0.05;
        break;

    case '5':
        fog_on = !fog_on;
        break;

    case '7':
        ball_2 =!ball_2;
        break;
    case '8':
        ball_3 =!ball_3;
        break;


    case 't':
        eye[1]++;
        look[1]++;
        break;
    case 'g':
        eye[1]--;
        look[1]--;
        break;
    case 'h':
        look[0]+=2;
        break;
    case 'f':
        look[0]-=2;
        break;
    case 'w':
        eye[2] = ball_pos_z+50;

        ball_int_rot -= 10;
        ball_int_rot_x = 1;
        if(ball_pos_z<=78 && ball_pos_z>=55)
        {
            ball_pos_z -=0;
        }
        else
        {
            ball_pos_z -=1;
        }



        if(ball_speed_in)
        {
            //cout<<" ball_speed "<< ball_speed<<endl;
            ball_speed +=2;
        }
        //cout<<ball_pos_z<<endl;
        break;
    case 's':
        eye[2] = ball_pos_z+50;

        ball_int_rot += 10;
        ball_int_rot_x = 1;
        if(ball_pos_z<=78 && ball_pos_z>=55)
            ball_pos_z +=0;
        else
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
        ball_left -=1;
        //ball_init
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


    case ' ':
        end_scene_status = false;
        break;
    case 'x':
        //jump
        if(jump_key_enable)
        {
            ball_jump_cond = !ball_jump_cond;
            jump_forward = !jump_forward;
        }
        break;
    case 'z':
        //jump
        if(jump_key_enable)
        {
            ball_jump_cond = !ball_jump_cond;
            jump_back = !jump_back;
        }


        break;
    case 'p':
        game_over = 0;
        ball_left = 3;
        ball_pos_x = 0, ball_pos_y = radius+(6/2), ball_pos_z = 130;
        eye[0] = 0;
        eye[1] = 50;
        eye[2] = 180;

        look[0] = 0;
        look[1] = 50;
        look[2] = -200;
        break;

    }


    glutPostRedisplay();
}
