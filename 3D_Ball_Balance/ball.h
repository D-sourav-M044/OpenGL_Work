
float surface_len = 0, surface_height = 0, surface_width = 0;

float radius = 8;

float  ball_speed = 0;
bool ball_speed_in = false;
bool ball_jump_cond = false;

float ball_pos_x = 0, ball_pos_y = radius+(6/2), ball_pos_z = 130;

bool ball_pos_store_chance = true;
float ball_st_pos_x = 0, ball_st_pos_y = radius+(6/2), ball_st_pos_z = 130;


float ball_rot = 0;
float ball_rot_x = 0, ball_rot_y = 0, ball_rot_z = 0;


float ball_fall = 0;
float ball_fall_rot = 0;
float ball_fall_rot_x = 0, ball_fall_rot_y = 0, ball_fall_rot_z = 0;
float ball_fall_tr_x = 0, ball_fall_tr_y = 0,  ball_fall_tr_z = 0;

float ball_int_rot= 1;
float ball_int_rot_x = 0, ball_int_rot_y = 0, ball_int_rot_z = 0;


float ball_fall_x = 0, ball_fall_y = 0, ball_fall_z = 0;



void ball_material_property()
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    //GLfloat mat_emission[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {30};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    //glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission);
}

void store_ball_pos(bool st_pos = false)
{
    ball_pos_store_chance = st_pos;
    if(ball_pos_store_chance)
    {
        ball_pos_store_chance = !ball_pos_store_chance;
        //cout<<"stored"<<endl;
        ball_st_pos_x = ball_pos_x, ball_st_pos_y = ball_pos_y, ball_st_pos_z = ball_pos_z;
    }
}

void ball_jump()
{
    if(ball_jump_cond && ball_speed_in)
    {
//        ball_fall_rot -= 45;
//        ball_fall_rot_x += 1;
        // ball_fall_tr_y  += 1;
        ball_pos_z -= ball_speed;
        ball_pos_y -= ball_speed;
    }
    else
    {
        ball_fall_rot =0;
        ball_fall_rot_x = 0;
        ball_fall_tr_y  = 0;
        ball_pos_z -= 0;
    }
    glutPostRedisplay();
}

int inc_ball_fall()
{
    if(ball_fall_y>-300)
        ball_fall_y-=1*ball_fall;
    glutPostRedisplay();
}
void sphere()
{
    ball_material_property();
    glPushMatrix();
    glutSolidSphere(radius,16,40);
    glPopMatrix();
}

void torus(float R = 0.5, float G = 0.5, float B = 0.5, float den = 1, float area = radius)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { R, G, B, 1.0 };
    GLfloat mat_diffuse[] = { R, G, B, 1.0 };
    //GLfloat mat_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    //GLfloat mat_specular[] = { 1, 1, 0, 1.0 };
    GLfloat mat_shininess[] = {30};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);


    glPushMatrix();
    //glutSolidSphere(8,20,16);
    glutSolidTorus(den,area,16,16);
    glPopMatrix();
}

void ball()
{

    store_ball_pos();
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, 1);
    ball_material_property();

    glPushMatrix();
    glRotatef(ball_fall_rot,ball_fall_rot_x,ball_fall_rot_y,ball_fall_rot_z);
    //glTranslatef(ball_fall_tr_x,ball_fall_tr_y,ball_fall_tr_z);

    glPushMatrix();
    glTranslatef(ball_fall_x, ball_fall_y, ball_fall_z);

    glPushMatrix();
    glTranslatef(ball_pos_x, ball_pos_y, ball_pos_z);
    glRotatef(ball_int_rot,ball_int_rot_x,ball_int_rot_y,ball_int_rot_z);





//
//
////
//
//    glPopMatrix();


    //sphere();
    glPushMatrix();

//    torus(1,0,1);
//
//    //horizontal torus
//    glPushMatrix();
//    glRotatef(90,1,0,0);
//    torus(1,1,1);
//    glPopMatrix();
//
//    //vertical torus
//    glPushMatrix();
//    glRotatef(90,0,1,0);
//    glRotatef(40,0,1,0);
//    torus(1,0,1);
//    glPopMatrix();
//
//    glRotatef(90,0,1,0);
//    glRotatef(-40,0,1,0);
//    torus(1,0,1);
//    glPopMatrix();

    drawball(radius);
    glPopMatrix();

    glPopMatrix();


    glPopMatrix();
    inc_ball_fall();
    //ball_jump();
    glPopMatrix();

    //glDisable(GL_TEXTURE_2D);
}




void ball_fall_down()
{

    glPushMatrix();
    glRotatef(10,0,0,1);
    glPushMatrix();
    glTranslatef(0,-ball_fall,0);
    ball();
    glPopMatrix();

    inc_ball_fall();
    glPopMatrix();
}
