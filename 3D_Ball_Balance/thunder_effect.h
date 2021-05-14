
bool thunder = false;
float rand_x =0, rand_y = 0, rand_z = 0, rand_n = 0;
float thund_time = 1000;
void thunder_on(int val);
bool rand_x_minus = true;

void rand_gen_x(int l, int u)
{
    float n;
    n = (rand() % (u-l+1));
    if(rand_x_minus)
    {
        rand_x_minus = !rand_x_minus;
        rand_x = n*(-1);
    }
    else
    {
        rand_x_minus = !rand_x_minus;
        rand_x = n;
    }
}

void rand_gen_y(int l, int u)
{
    float n;
    n = (rand() % (u-l+1));
    rand_y = n;
}

void rand_gen_z(int l, int u)
{
    float n;
    n = (rand() % (u-l+1));
    rand_z = -n;

}


void thunder_off(int val)
{
    if(thunder)
        thunder = !thunder;
    glutTimerFunc(3000,thunder_on,0);
}

void thunder_on(int val)
{
    if(!thunder)
        thunder = !thunder;
    glutTimerFunc(1000,thunder_off,0);
}

void thunder_timer()
{
    if(!thunder)
    {
        rand_gen_x(-400,450);
        rand_gen_y(350,400);
        rand_gen_z(-1500,-850);
        glutTimerFunc(3000,thunder_on,1);
    }

    else
    {
        rand_gen_x(-400,450);
        rand_gen_y(350,400);
        rand_gen_z(-1500,-850);
        glutTimerFunc(1000,thunder_off,0);
    }
}
void thunder_call(int val)
{
    if(val)
    {
        val = !val ;
        thund_time += 2000;
        thunder_timer();
    }
    glutTimerFunc(thund_time, thunder_call, 1);

}
void thund_object(float thun_len, float thun_height, float thun_width, float block_height );


void thunder_effect()
{

    float thun_len = 2, thun_height = 200, thun_width = 1;
    float block_height = 40;
    thunder_call(0);

    if(thunder)
    {
    glPushMatrix();
    glTranslatef(0,0,-200);
    glTranslatef(rand_x,rand_y,rand_z);
    thund_object(2,200,1,40);
    glPopMatrix();
    }


}


void thund_object(float thun_len = 5, float thun_height = 200, float thun_width = 1, float block_height = 1)
{

//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D,13);
//
//    glPushMatrix();
//    glTranslatef(0,400,0);
//    glScalef(5*block_height, 200, block_height);
//    glTranslatef(-0.5,-0.5,-0.5);
//    cube(0.0,0.0,1,1,1);
//    glPopMatrix();

        //01
    bool t_flag = 1;
    for(int i = 1200; i>=100; i-=20)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,13);

        glPushMatrix();
        glTranslatef(0,i,0);
        if(t_flag)
        {
            glRotatef(10,0,0,1);
            t_flag = !t_flag;
        }
        else
        {
            glRotatef(-10,0,0,1);
            t_flag = !t_flag;
        }
        glScalef(1,20,2);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.0,0.0,1,1,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }

    //02
    for(int i=-1;i<=1;i+=2)
    {
        t_flag = 1;
    glPushMatrix();
    glRotatef(i*10,0,0,1);
    glTranslatef(i*200,0,0);
    for(int i = 800; i>=-100; i-=20)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,13);

        glPushMatrix();
        glTranslatef(0,i,0);
        if(t_flag)
        {
            glRotatef(10,0,0,1);
            t_flag = !t_flag;
        }
        else
        {
            glRotatef(-10,0,0,1);
            t_flag = !t_flag;
        }
        glScalef(2,20,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.0,0.0,1,1,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    /////////l
    glPushMatrix();
    glRotatef(i*10,0,0,1);
    glTranslatef(i*i*35,0,0);
    for(int i = 200; i>=-100; i-=20)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,13);

        glPushMatrix();
        glTranslatef(0,i,0);
        if(t_flag)
        {
            glRotatef(10,0,0,1);
            t_flag = !t_flag;
        }
        else
        {
            glRotatef(-10,0,0,1);
            t_flag = !t_flag;
        }
        glScalef(1,20,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.0,0.0,1,1,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
    }

    //02
    glPushMatrix();
    glRotatef(10,0,0,1);
    glTranslatef(35,0,0);
    for(int i = 200; i>=0; i-=20)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,13);

        glPushMatrix();
        glTranslatef(0,i,0);
        if(t_flag)
        {
            glRotatef(10,0,0,1);
            t_flag = !t_flag;
        }
        else
        {
            glRotatef(-10,0,0,1);
            t_flag = !t_flag;
        }
        glScalef(1,20,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.0,0.0,1,1,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
    //03
    glPushMatrix();
    glRotatef(-10,0,0,1);
    glTranslatef(-35,0,0);
    for(int i = 200; i>=0; i-=20)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,13);

        glPushMatrix();
        glTranslatef(0,i,0);
        if(t_flag)
        {
            glRotatef(10,0,0,1);
            t_flag = !t_flag;
        }
        else
        {
            glRotatef(-10,0,0,1);
            t_flag = !t_flag;
        }
        glScalef(1,20,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.0,0.0,1,1,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
    //04
    glPushMatrix();
    glRotatef(-10,0,0,1);
    glTranslatef(0,0,0);
    for(int i = 100; i>=-100; i-=20)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,13);

        glPushMatrix();
        glTranslatef(0,i,0);
        if(t_flag)
        {
            glRotatef(10,0,0,1);
            t_flag = !t_flag;
        }
        else
        {
            glRotatef(-10,0,0,1);
            t_flag = !t_flag;
        }
        glScalef(1,20,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.0,0.0,1,1,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    //05
    glPushMatrix();
    glRotatef(10,0,0,1);
    glTranslatef(35,0,0);
    for(int i = 100; i>=-400; i-=20)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,13);

        glPushMatrix();
        glTranslatef(0,i,0);
        if(t_flag)
        {
            glRotatef(10,0,0,1);
            t_flag = !t_flag;
        }
        else
        {
            glRotatef(-10,0,0,1);
            t_flag = !t_flag;
        }
        glScalef(1,20,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.0,0.0,1,1,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    //06
    glPushMatrix();
    glRotatef(10,0,0,1);
    glTranslatef(35,0,0);
    for(int i = 0; i>=-100; i-=20)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,13);

        glPushMatrix();
        glTranslatef(0,i,0);
        if(t_flag)
        {
            glRotatef(10,0,0,1);
            t_flag = !t_flag;
        }
        else
        {
            glRotatef(-10,0,0,1);
            t_flag = !t_flag;
        }
        glScalef(1,20,1);
        glTranslatef(-0.5,-0.5,-0.5);
        cube(0.0,0.0,1,1,1);
        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

}
