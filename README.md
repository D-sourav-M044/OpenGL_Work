# OpenGL_Work
 Graphics Lab Assignment and Lab work through glut project with OpenGL

OpenGL/GLUT Project in code::block

## step 1: Glut setup <br>
* Download glut-3.7.6-bin from Google or goto OpenGL_Work\Glut_setup\glut-3.7.6-bin <br>
* There will be at least 3 files. (glut.h, glut32.dll, glut32.lib) <br>
* go location : C:\Program Files (x86)\CodeBlocks\MinGW\include <br>
	in GL folder, paste glut.h
* go location: C:\Program Files (x86)\CodeBlocks\MinGW\lib, paste glut32.lib
* go C:\Windows\SysWOW64 , paste glut32.dll
	Note: If your Operating System is 32 bit, Folder name might be C:\Windows\System32

## step 2:  Linker settings for Codeblocks
* Select settings -- select compiler -- linker settings-  press clear
* press add, location: C:\Program Files (x86)\CodeBlocks\MinGW\lib
* add: glut32.lib, libglu32.a, libopengl32.a
* press ok


## step 3:
* Open the code block and click on create new porject .

## step 4:
* click on GLUT project , click next
* Enter project title name, give path to save project and project file name is created by default from project title name.
After that click next.

## Step 5:
* now give the path "C:\Program Files\CodeBlocks\MinGW" for glut location
* Then click next.
* Now click finish

## step 6:
* Finally project is created and you will get default main.cpp file and don't forget to write  "#include<GL/gl.h> and #include<windows.h>" header file otherwise you may get error now built and run it will see window as below.

 
	If you see the output of some rotating images then you have successfully created a project.
