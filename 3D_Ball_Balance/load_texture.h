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

}
