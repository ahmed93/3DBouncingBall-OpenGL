//
//  Texture.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 12/11/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Texture.h"

// Data read from the header of the BMP file
unsigned char header[54]; // Each BMP file begins by a 54-bytes header
unsigned int dataPos;     // Position in the file where the actual data begins
unsigned int width, height;
unsigned int imageSize;   // = width*height*3
// Actual RGB data
unsigned char * data;

GLuint Texture::loadBMP_custom(const char * imagepath)
{

    return 0;
}
