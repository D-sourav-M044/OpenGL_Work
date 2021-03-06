GLfloat ctrlpoints[4][3] =
{
    { -4.0, -4.0, 0.0},
    { -2.0, 4.0, 0.0},
    {2.0, -4.0, 0.0},
    {4.0, 4.0, 0.0}
};

void cur()
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat) i/30.0);
    glEnd();
    /* The following code displays the control points as dots. */
    glPointSize(5.0);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for (i = 0; i < 4; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();
    glFlush();
    glutSwapBuffers();
}
