

bool starting_view_animation_z = end_scene_status;
bool starting_view_animation_x = end_scene_status;
//bool starting_view_animation_z = false;
//bool starting_view_animation_x = false;


void view_animation()
{
    if (starting_view_animation_z)
    {
        eye_ani[2] +=0.5 ;
        look_ani[2] +=0.5;

        if(eye_ani[2]== 130)
        {
            starting_view_animation_z = false;
            starting_view_animation_x = true;
        }

    }
    if (starting_view_animation_x)
    {
        eye_ani[0] -=0.5 ;
        look_ani[0] -=0.5;

        if(eye_ani[0]== 100)
        {
            starting_view_animation_z = false;
            starting_view_animation_x = false;
            end_scene_status = false;
        }

    }

    glutPostRedisplay();
}

void starting_view()
{ glPushMatrix();
    if(end_scene_status)
    { obj_mat(1,0,0);


        glEnable(GL_LINE_SMOOTH);
        glLineWidth(10.0);
        glPushMatrix();
        glRasterPos3f(450,30,-80);
        //glTranslatef(-150,800,0);


        char msg[] = "Press [space_bar] to start the game";
        for(int i=0; i<strlen(msg); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);

        glPopMatrix();

    }

    view_animation();
    glPopMatrix();
}
