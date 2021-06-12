int game_over = 0;
bool position_check(float x = 0,float y = 0,float z = 0,  float center =0,  bool origin_change = 0, float center_x = 0, bool jump = 0, float rot = 0)
{
    if(origin_change)
    {
        if( ( ball_pos_x>= -x + (center_x) && ball_pos_x<= x + (center_x)) && (ball_pos_y == radius + y ) && (ball_pos_z<= center + abs(z) && ball_pos_z>= center-abs(z)) )
            return true;
        else
            return false;
    }
    else if(jump)
    {
        if( ( ball_pos_x>= -x + (center_x) && ball_pos_x<= x + (center_x))  && (ball_pos_z<= center + abs(z) && ball_pos_z>= center-abs(z)) )
            return true;
        else
            return false;
    }
    else
    {
        if( ( ball_pos_x>= -x && ball_pos_x<= +x) && (ball_pos_y == radius + y ) && (ball_pos_z<= center + abs(z) && ball_pos_z>= center-abs(z)) )
            return true;
        else
            return false;
    }

}
void load_area(int area_no, float x=0, float y=radius+3, float z=0, bool origin = 0)
{
    area[area_no][0]=-x/2;
    area[area_no][1]=x/2;
    area[area_no][2]=-y/2;
    area[area_no][3]=y/2;
    area[area_no][4]=-z/2;
    area[area_no][5]=z/2;
}
bool fall_detection(float angle=0)
{

    int sum = 0;
    for(int i=0; i<10; i++)
    {
        sum+=port[i];
    }
    if(!sum)
    {

        if(game_over)
        {
            //cout<<"sesh"<<endl;
            //glutDestroyWindow(300);

        }




        obj_mat(1,1,0);


        glEnable(GL_LINE_SMOOTH);
        glLineWidth(5.0);

        glPushMatrix();
        glRasterPos3f(ball_pos_x-7,ball_pos_y+20,ball_pos_z+20);
        glScalef(10,10,10);

        string msg = "press [n] for new ball";

        for(int i=0; i<msg.size(); i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);

        glPopMatrix();

        ball_fall = 1;
        ball_fall_rot = 5*angle;
        ball_fall_rot_z = 1;
    }
    else if(sum)
    {
        if( ball_left==0)
        {
            game_over = 1;
        }
        ball_fall = 0;
        ball_fall_rot = 0;
        ball_fall_rot_z = 0;
    }
    //cout<<"sum = "<<sum<<endl;
}
