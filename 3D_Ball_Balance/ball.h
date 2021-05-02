
float surface_len = 0, surface_height = 0, surface_width = 0;

float radius = 8;
float ball_pos_x = 0, ball_pos_y = radius+(6/2), ball_pos_z = 20;

float ball_rot = 0;
float ball_rot_x = 0, ball_rot_y = 0, ball_rot_z = 0;


float ball_fall = 0;
float ball_fall_rot = 0;
float ball_fall_rot_x = 0, ball_fall_rot_y = 0, ball_fall_rot_z = 0;

float ball_fall_x = 0, ball_fall_y = 0, ball_fall_z = 0;

void ball_material_property()
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
    GLfloat mat_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat mat_emission[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {30};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission);
}

int inc_ball_fall()
{
    if(ball_fall_y>-100)
        ball_fall_y-=1*ball_fall;
    glutPostRedisplay();
}

void ball()
{


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 1);
    //ball_material_property();

    glPushMatrix();
    glRotatef(ball_fall_rot,ball_fall_rot_x,ball_fall_rot_y,ball_fall_rot_z);

    glPushMatrix();
    glTranslatef(ball_fall_x, ball_fall_y, ball_fall_z);

    glPushMatrix();
    glTranslatef(ball_pos_x, ball_pos_y, ball_pos_z);
    glutSolidSphere(radius,16,40);
    glPopMatrix();


    glPopMatrix();
    inc_ball_fall();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
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
