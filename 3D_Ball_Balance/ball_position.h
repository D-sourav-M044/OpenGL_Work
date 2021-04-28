
bool position_check(float x = 0, float y = 0, float z = 0, float rot = 0)
{
    if( ( ball_x_pos>= -x && ball_x_pos<= +x) && (ball_y_pos == radius + y ) && (ball_z_pos>= -z && ball_z_pos<= +z) )
        return true;
    else
        return false;
}
