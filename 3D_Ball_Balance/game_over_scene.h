


void game_over_scene()
{





            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            glEnable(GL_LINE_SMOOTH);
            glLineWidth(4.0);

            glPushMatrix();
            obj_mat(1,0,0);
            //glRasterPos3f(ball_pos_x,ball_pos_y+40,ball_pos_z+20);
            //glTranslatef(ball_pos_x-20,ball_pos_y+40,ball_pos_z+20);
            //glTranslatef(ball_pos_x-20,ball_pos_y+40,ball_pos_z+20);
            glTranslatef(-5,60,150);


            glScalef(0.02,0.05,0.01);
            string msg;
             msg = "Game over";

            for(int i=0; i<msg.size(); i++)
                // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
                glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,msg[i]);

            glPopMatrix();



            glPushMatrix();
            obj_mat(0,1,0);
            //glRasterPos3f(ball_pos_x,ball_pos_y+40,ball_pos_z+20);
            //glTranslatef(ball_pos_x-20,ball_pos_y+40,ball_pos_z+20);
            //glTranslatef(ball_pos_x-20,ball_pos_y+40,ball_pos_z+20);
            glTranslatef(-20,50,150);


            glScalef(0.02,0.05,0.01);
            string msg1;
             msg1 = "Press 'p' to start again";

            for(int i=0; i<msg1.size(); i++)
                // glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
                glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,msg1[i]);

            glPopMatrix();





}
