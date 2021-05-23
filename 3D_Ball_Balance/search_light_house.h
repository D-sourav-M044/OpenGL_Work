float tower_con_rot = 0 ;
void tower_con_rot_cal()
{
    tower_con_rot += 1;
    if(tower_con_rot >=360)
        tower_con_rot = 0;
    glutPostRedisplay();
}

void tower_sphere_atr(float R=0.5, float G =0.5, float B =0.5)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { R, G, B, 1.0 };
    GLfloat mat_diffuse[] = { R, G, B, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {30};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
}
void search_light_house()
{

    float dec = 2.5;
    bool tower_col = true;
    float tower_height = 1000;


    glPushMatrix();
    glTranslatef(500,-200,-400);



    for(int i=0; i<=tower_height; i+=20)
    {
        glPushMatrix();
        glTranslatef(0,i-dec,0);
        glScalef(200-dec,20,200-dec);
        glTranslatef(-0.5,-0.5,-0.5);
        if(tower_col)
        {
            tower_col = !tower_col;
            cube();
        }

        else
        {
            tower_col = !tower_col;
            cube(0.5,0,0);
        }
        glPopMatrix();
        dec+=2.5;
    }

    //con-handle
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);

    glPushMatrix();
    glTranslatef(0,tower_height,0);
    glTranslatef(0,-150,0);
    glScalef(20,300,20);
    glTranslatef(-0.5,-0.5,-0.5);
    cube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    //con
    glPushMatrix();
    glRotatef(tower_con_rot,0,1,0);

    glPushMatrix();
    glTranslatef(0,tower_height,0);
    glRotatef(120,1,0,0);
    torch_top(50);
    tower_con_rot_cal();
    glPopMatrix();

    //ball_light
    glPushMatrix();
    glTranslatef(0,tower_height-16,20);
    glRotatef(60,1,0,0);
    glutSolidSphere(16,16,16);
    spot_light_effect(0,tower_height,20, 30);
    glPopMatrix();



    tower_con_rot_cal();

    glPopMatrix();



    glPopMatrix();

}
