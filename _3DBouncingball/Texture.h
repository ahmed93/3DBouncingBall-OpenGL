    //
//  Texture.h
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 12/11/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#ifndef ___3DBouncingball__Texture__
#define ___3DBouncingball__Texture__

#include "Constants.h"

// Load a .BMP file using our custom loader
GLuint loadBMP_custom(const char * imagepath);

//// Since GLFW 3, glfwLoadTexture2D() has been removed. You have to use another texture loading library,
//// or do it yourself (just like loadBMP_custom and loadDDS)
//// Load a .TGA file using GLFW's own loader
//GLuint loadTGA_glfw(const char * imagepath);

// Load a .DDS file using GLFW's own loader
GLuint loadDDS(const char * imagepath);



#endif /* defined(___3DBouncingball__Texture__) */
