
float bar_pos_x = 0, bar_pos_x_var = 0.1;
float pipe_angle = 0;
void bar_pos_x_cal()
{
    bar_pos_x += bar_pos_x_var;
    pipe_angle = (asin(bar_pos_x/100) * 180)/3.14;
    //cout<<pipe_angle<<endl;
    if( bar_pos_x >= 40)
        bar_pos_x_var = -0.1;
    if( bar_pos_x <= -40)
        bar_pos_x_var = 0.1;

    glutPostRedisplay();
}

void road()
{
    //port -4
    float road_len = 100, road_height = 6, road_width = 150;

    //position check
    bool here = position_check(road_len/2, road_height/2, road_width/2, -(road_width/2 + 10));
    if(here)
    {
        port[4]=1;
        cout<<"in road"<<endl;
    }
    else
    {
        port[4] = 0;
        fall_detection();
    }


    glPushMatrix();
    glTranslatef(0,0,-(road_width/2 + 10));

    //road && roof
    for(int i=0; i<=1; i++)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 3);

        glPushMatrix();
        glTranslatef(0,i*250,0);
        glScalef(road_len, road_height, road_width);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }

    //upper pilar
    float pilar_height = 250, pilar_den = 5;
    for(float i = -1; i<=1; i+=2)
    {
        for(float j = -1; j<=1; j+=2)
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, 3);
            glPushMatrix();
            glTranslatef(j*(road_len/2-pilar_den/2-0.5),pilar_height/2,i*(road_width/2-pilar_den/2-0.5));
            glScalef(pilar_den,pilar_height,pilar_den);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.5,0.3,0.4);
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);
        }
    }

    //lower pilar
    float lower_pilar_height = 250, lower_pilar_den = 20;
    for(float i = -1; i<=1; i++)
    {
        for(float j = -1; j<=1; j++)
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, 3);

            glPushMatrix();
            glTranslatef(j*(road_len/2-pilar_den/2-0.5),-pilar_height/2,i*(road_width/2-pilar_den/2-0.5));
            glScalef(lower_pilar_den,lower_pilar_height,lower_pilar_den);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.5,0.3,0.4);
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);
        }
    }

    //hanging bars;
    bool hanging_bar_flag = false;
    float loop_angle, bar_x = 1;
    for(int pos=-70; pos<=70; pos+=30)
    {
        if(hanging_bar_flag)
        {
            loop_angle = -1;
            bar_x = -1;
            hanging_bar_flag = !hanging_bar_flag;
        }
        else
        {
            loop_angle = 1;
            bar_x = 1;
            hanging_bar_flag = !hanging_bar_flag;
        }





        glPushMatrix();
        glRotatef(pipe_angle/2,0,0,loop_angle);
        glTranslatef(bar_x*bar_pos_x,0,0);
        //wire
        float wire_height = 250;
        for(int i=-30; i<=30; i+=60)
        {
            glPushMatrix();
            glTranslatef(i,0,pos);
            glTranslatef(0,wire_height/2 + 10,0);
            glScalef(0.5,wire_height,0.5);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.5,0.4,0.3);
            glPopMatrix();
        }

        //hanging bar
        float bar_len = 60, bar_height = 10, bar_width = 5;
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 3);

        glPushMatrix();
        glTranslatef(0,10,pos);
        glScalef(bar_len,bar_height,bar_width);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(1,1,0);
        bar_pos_x_cal();
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);


        glPopMatrix();

        bool ball_collition_x = ((ball_pos_x <= (bar_x*bar_pos_x+bar_len/2-radius)) && (ball_pos_x >= (bar_x*bar_pos_x-bar_len/2-radius)) );

        bool ball_collition_z_1 = ((pos+bar_width/2)-85 <= ball_pos_z+radius) && ((pos+bar_width/2)-85 >= ball_pos_z-radius) ;
        bool ball_collition_z_2 = ((pos-bar_width/2)-85 <= ball_pos_z+radius) && ((pos-bar_width/2)-85 >= ball_pos_z-radius) ;
        bool ball_collition_z = ( ball_collition_z_1 || ball_collition_z_2 );
        if( ball_collition_x  && ball_collition_z )
        {
            cout<<"milche"<<endl;
            ball_pos_x += bar_x*bar_pos_x;

        }




        //fixed bar
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 11);

        glPushMatrix();
        glTranslatef(0,pilar_height-10,pos);
        glScalef(100,30,5);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.5,0,0.2);
        bar_pos_x_cal();
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);


    }

    glPopMatrix();




}
