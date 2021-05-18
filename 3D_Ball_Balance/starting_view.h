
bool starting_view_animation_z = true;
bool starting_view_animation_x = true;
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
        }

    }

    glutPostRedisplay();
}

void starting_view()
{
    glPushMatrix();
    view_animation();
    glPopMatrix();
}
