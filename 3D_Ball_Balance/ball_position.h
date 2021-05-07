
bool position_check(float x = 0, float y = 0, float z = 0, float center =0, bool origin = 0, float rot = 0)
{
    if(origin)
    {
        if( ( ball_pos_x>= -x && ball_pos_x<= +x) && (ball_pos_y == radius + y ) && (ball_pos_z<= z && ball_pos_z>= -z) )
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
        ball_fall = 1;
        ball_fall_rot = 5*angle;
        ball_fall_rot_z = 1;
    }
    else if(sum)
    {
        ball_fall = 0;
        ball_fall_rot = 0;
        ball_fall_rot_z = 0;
    }
}
