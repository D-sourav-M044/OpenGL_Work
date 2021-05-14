



void *fonts[] =
{GLUT_STROKE_ROMAN, GLUT_STROKE_MONO_ROMAN};


// GLUT_STROKE_ROMAN has variable width:

void *font = GLUT_STROKE_ROMAN;

char defaultMessage[] = "GLUT means OpenGL.";
char *message = defaultMessage;

void selectFont(int newfont)
{
    font = fonts[newfont];
    glutPostRedisplay();
}



void score_board()
{

    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { 1, 0, 0, 1.0 };
    GLfloat mat_diffuse[] = { 1, 0, 0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_emission[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = {255};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
//
//
//    int len, i;
//    glPushMatrix();
//    glTranslatef(-500, 200, -100);
//    len = (int) strlen(message);
//    glColor3f(1,1,1);
//    for (i = 0; i < len; i++)
//    {
//        glutStrokeCharacter(font, message[i]);
//    }
//    glPopMatrix();

//    glColor3f(1,0,0);
//    glRasterPos3f(-50,0,50);

    glEnable(GL_LINE_SMOOTH);
    glLineWidth(5.0);
    glPushMatrix();
    glRasterPos3f(-50,140,0);
    glTranslatef(-150,800,-400);


    char msg[] = "3D_Ball_Balance";
    for(int i=0; i<strlen(msg); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
//for (int i = 0; i < strlen(msg); i++)
//    {
//        glutStrokeCharacter(GLUT_STROKE_ROMAN, msg[i]);
//    }
    glPopMatrix();




}
