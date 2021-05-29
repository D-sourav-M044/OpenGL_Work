unsigned int ID;
#define GL_CLAMP_TO_EDGE 0x812F

void LoadTexture(const char*filename, int rep = 1)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if(rep)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }

    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}

void load_images()
{
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\flr.bmp",1);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\ball-3.bmp",2);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\normal_flr.bmp",3);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\up_down_flr.bmp",4);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\up_down.bmp",5);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\ball.bmp",6);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\devil.bmp",7);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\ocean_water.bmp",8);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\hill.bmp",9);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\dragon.bmp",10);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\dark_pyramid.bmp",11);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\thunder_light.bmp",12);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\up_thund.bmp",13);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\brick_road.bmp",14);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\fire_flame.bmp",15);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\front.bmp",16);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\sky.bmp",17);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\kuet_logo.bmp",18);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\ice_hill.bmp",19);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\finish_flr.bmp",20);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\side2.bmp",21);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\w.bmp",22);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\s.bmp",23);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\d.bmp",24);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\a.bmp",25);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\dir_arrow.bmp",26);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\maze.bmp",27);
     LoadTexture("C:\\Users\\Admin\\Desktop\\3D_Ball_Balance\\images\\danger.bmp",28);

}
