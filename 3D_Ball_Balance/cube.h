static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
//    {0,2,6,4},
//    {5,7,3,1},
//    {0,4,5,1},
//    {3,7,6,2},
//    {0,1,3,2},
//    {6,7,5,4}

    {3,1,5,7}, //front
    {2,0,1,3}, //left
    {7,5,4,6}, //r
    {2,3,7,6}, //top
    {1,0,5,4}, //bot
    {6,4,0,2} //back
};
static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void material_property(float R, float G, float B, bool li )
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { R, G, B, 1.0 };
    //GLfloat mat_ambient[] = { 0, 0, 0, 1.0 };
    GLfloat mat_diffuse[] = { R, G, B, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    //GLfloat mat_emission[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {255};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);

    //glMaterialfv( GL_FRONT, GL_EMISSION, mat_emission);

}
void cube(float R=0.5, float G=0.5, float B=0.5, bool li = false, int no_image = 1)
{
    material_property(R,G,B,li);
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
//                glColor3f(R,G,B);
//
//                R += 0.05;
//                G += 0.05;
//                B += 0.05;
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

//        for (GLint j=0; j<4; j++)
//        {
//            glVertex3fv(&v_cube[c_ind[i][j]][0]) ;
//            glTexCoord2f(1,1);
//        }
        glTexCoord2f(no_image,no_image);
        glVertex3fv(&v_cube[c_ind[i][0]][0]);
        glTexCoord2f(0,no_image);
        glVertex3fv(&v_cube[c_ind[i][1]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&v_cube[c_ind[i][2]][0]);
        glTexCoord2f(no_image,0);
        glVertex3fv(&v_cube[c_ind[i][3]][0]);

    }
    glEnd();
}
