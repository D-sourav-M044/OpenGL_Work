
float inc = 0.25;
bool flag = false;
bool flr_move = false;
bool ok = true;

void on_move(int val)
{
    ok = val;
    flr_move = val;
}
float flr_rot_i= 0;
void flor_rot()
{
    if(ok && flr_move)
    {
        flr_rot_i+= inc;
        if(flr_rot_i>30)
        {
            inc = -0.25;
        }

        else if(flr_rot_i<-30)
            inc = 0.25;
        if (flr_rot_i==0)
        {
            ok= false;
            flr_move = false;
            glutTimerFunc(2000,on_move,1);
        }
    }
    else
    {
        flr_rot_i=0;
    }


    glutPostRedisplay();
}


void connected_objects(float len = 70, float height = 6, float width = 20, float angle=0)
{
    for(int trx = -1; trx<=1; trx+= 2)
    {
        glPushMatrix();
        glTranslatef(trx*(len/2-10),100,0);
        glRotatef(angle,0,0,(ok&flr_move));
        for(int i=0; i<= 360; i+= 25)
        {
            glPushMatrix();
            glRotatef(i,0,0,1);
            glTranslatef(15/2,0,0);
            glScalef(15,2,1);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(0.502, 0.502, 0.000);
            glPopMatrix();
        }
        glutSolidTorus(2,15,16,16);
        glPopMatrix();


        //wire
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,15);

        glPushMatrix();
        glTranslatef(trx*(len/2-10),50,0);
        glScalef(1,100-(trx*((angle))*(ok&flr_move)),1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();



        //horizontal
        glPushMatrix();
        glTranslatef(0,100,0);
        glScalef(40,1,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);



        for(int i=-1; i<=1; i+=2)
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,4);

            //wire box-horizontal border
            for(int i=80; i<=120; i+=40)
            {
                glPushMatrix();
                glTranslatef(0,i,0);
                glScalef(len+20,1,20);
                glTranslatef(-0.5,-0.5,-0.5);
                cube();
                glPopMatrix();
            }
            //wire box-verticall border
            glPushMatrix();
            glTranslatef(i*((len+20)/2-0.5),100,0);
            glScalef(1,40,20);
            glTranslatef(-0.5,-0.5,-0.5);
            cube();
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);


            //connection bar
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,3);

            glPushMatrix();
            glTranslatef(i*((len+20)/2+(len/2+50)/2),150,0);
            glScalef(len/2+80,2,2);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(1,1,0);
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);

            //virtical
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,3);

            glPushMatrix();
            glTranslatef(i*((len)/2-5),150-12.5,0);
            glScalef(2,25,2);
            glTranslatef(-0.5,-0.5,-0.5);
            cube(1,1,0);
            glPopMatrix();

            glDisable(GL_TEXTURE_2D);
        }
    }
}

void pilar_flr(float len = 70, float height = 6, float width = 20, float angle=0)
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,8);

    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*((len+ 50)),-100,0);
        glScalef(40,200,40);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);

    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*((len+ 50)),0,0);
        glScalef(20,40,20);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);

    //pillar-virtical
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);

    for(int i=-1; i<=1; i+=2)
    {
        glPushMatrix();
        glTranslatef(i*((len+ 50)),90,0);
        glScalef(5,140,5);
        glTranslatef(-0.5,-0.5,-0.5);
        cube();
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);

}

void floor()
{
    //port 1
    bool here = false;
    float len = 70, height = 6, width = 20;


    here = position_check(len/2, height/2, width/2, 100);
    flag = here;
    ok_ball = here;
    flr_move = here;
    if(here)
    {

        if(flr_move && ok)
        {
            port[1] = 1;

            ball_int_rot -= 5;
            ball_int_rot_z = 1;

            surface_len = len, surface_height = height, surface_width = width;
            ball_pos_x -= 2*(len/2*sin((inc*3.1416)/180));
            if(ball_rot<=flr_rot_i)
                ball_rot += inc;
            ball_rot_z = 1;

        }
        else
        {
            ball_rot_z = 0;
            ball_rot = 0;
        }

    }
    else
    {
        //cout<<"out"<<endl;
        port[1] = 0;
        fall_detection(inc);
        //ball_rot = 0;
    }


    glPushMatrix();
    glTranslatef(0,0,100);


    connected_objects(len,height,width,flr_rot_i);
    pilar_flr(len,height,width,flr_rot_i);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 1);
    glPushMatrix();
    glRotatef(flr_rot_i,0,0,1);

    glPushMatrix();
    glScalef(len,height,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.5,0,1,0,1);
    glPopMatrix();

    flor_rot();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();

}
