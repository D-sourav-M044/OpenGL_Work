
void ball_jump()
{
    if(ball_jump_cond && jump_forward)
    {

        if(ball_y_inc)
        {
            ball_pos_y +=1;
            ball_pos_z -=0.5;
            eye[2] -=0.5;
            look[2] -=0.5;
            if(ball_pos_y>=40)
            {
                ball_y_inc = false;
                ball_y_dec = true;
            }
        }
        else if(ball_y_dec)
        {
            ball_pos_y -=1;
            ball_pos_z -=0.5;
             eye[2] -=0.5;
            look[2] -=0.5;
            if(ball_pos_y==radius+(6/2))
            {
                ball_y_inc = true;
                ball_y_dec = false;
                ball_jump_cond = false;
                jump_forward = false;
            }
        }
    }
    if(ball_jump_cond && jump_back)
    {

        if(ball_y_inc)
        {
            ball_pos_y +=1;
            ball_pos_z +=0.5;
             eye[2] +=0.5;
            look[2] +=0.5;
            if(ball_pos_y>=40)
            {
                ball_y_inc = false;
                ball_y_dec = true;
            }
        }
        else if(ball_y_dec)
        {
            ball_pos_y -=1;
            ball_pos_z +=0.5;
            eye[2] +=0.5;
            look[2] +=0.5;
            if(ball_pos_y==radius+(6/2))
            {
                ball_y_inc = true;
                ball_y_dec = false;
                ball_jump_cond = false;
                jump_back = false;
            }
        }
    }
    glutPostRedisplay();
}
void danger_plot()
{


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,28);

    glPushMatrix();
    glTranslatef(0,16,70);
    glScalef(20,20,2);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(1,0,0);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}
void short_way()
{
    danger_plot();
    //port -3
    float way_len = 5, way_height = 6, way_width = 50;

    //position check
    bool here = position_check(way_len/2, way_height/2, way_width/2, 100-(10+way_width/2),0,0,1);


    if(here)
    {
        jump_key_enable = true;
        port[3]=1;
        ball_speed_in = true;
        store_ball_pos(1);
        ball_jump();

        //text
        if(!end_scene_status)
        {
            obj_mat(0,0,1);



            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            glEnable(GL_LINE_SMOOTH);
            glLineWidth(4.0);
            glPushMatrix();
            //glRasterPos3f(ball_pos_x,ball_pos_y+40,ball_pos_z+20);
            glTranslatef(ball_pos_x-20,48,ball_pos_z+20);

            glScalef(0.02,0.05,0.01);
            string msg;
            if(ball_pos_z>=70)
             msg = "press [x] to jump.";
            else
            msg = "press [z] to jump";


            for(int i=0; i<msg.size(); i++)
                // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
                glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,msg[i]);

            glPopMatrix();
        }


    }
    else if(!here && !ball_jump_cond)
    {
        jump_key_enable = false;
        port[3] = 0;
        fall_detection();
    }
    glPushMatrix();
    glTranslatef(0,0,100-(10+way_width/2));

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 14);

    glPushMatrix();
    glScalef(way_len, way_height, way_width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0.5,0.5,0,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();



    //port -4
    bool there = position_check(4*way_width/2, way_height/2, way_len/2, 100-(10+way_width+way_len/2));
    if(there)
    {
        port[4] = 1;
        ball_speed_in = true;
        store_ball_pos(1);
    }
    else
    {
        port[4] = 0;
        //ball_speed_in = false;
        fall_detection();
    }
    glPushMatrix();
    glTranslatef(0,0,100-(10+way_width+way_len/2));

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 14);

    glPushMatrix();
    glScalef(4*way_width, way_height, way_len);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0.5,0.5,0,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();


    //join pillar
    for(int i=-1; i<=1; i++)
    {
        glPushMatrix();
        glTranslatef(i*(4*way_width)/2,0,100-(10+way_width+way_len/2));

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 14);

        glPushMatrix();
        glTranslatef(0,-250,0);
        glScalef(10, 500, 10);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0,0,0,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);

        glPopMatrix();
    }


}
