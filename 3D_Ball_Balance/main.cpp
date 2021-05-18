#include "header.h"


const int window_width = 1200;
const int window_height = 700;
static int g_counter = 0;

void sound()
{
    sndPlaySound("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\sounds\\background_sound.wav", SND_ASYNC);

    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(window_width,window_height);
    glutInitWindowPosition(300,10);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    //
    glutCreateWindow("3D Ball Balance");

    load_images();

    time(&st_time);
    //glutDisplayFunc(display);
    glutDisplayFunc(welcomedisplay);
    //glutDisplayFunc(end_scene);
    //glutDisplayFunc(starting_view);
    glutKeyboardFunc(key);

    glutTimerFunc(4000,myTimer,0);

    cout<<double(end_time-st_time);

    extra_light();
    glEnable(GL_DEPTH_TEST);
    glShadeModel( GL_SMOOTH );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);
    //glEnable(GL_LIGHTING);



    //sound();
    glutMainLoop();



    //return EXIT_SUCCESS;
}
