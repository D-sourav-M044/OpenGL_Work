
bool position_check(float x = 0, float y = 0, float z = 0, float rot = 0)
{
    if( ( ball_pos_x>= -x && ball_pos_x<= +x) && (ball_pos_y == radius + y ) && (ball_pos_z>= -z && ball_pos_z<= +z) )
        return true;
    else
        return false;
}
