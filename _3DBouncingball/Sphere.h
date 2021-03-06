//
//  Sphere.h
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/25/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#ifndef ___3DBouncingball__Sphere__
#define ___3DBouncingball__Sphere__

#include "Constants.h"
#include "Game.h"

class Sphere {
protected:
    void drawS(mat4);
public:
    Sphere();

    void setTexture(char* filename);
    void writeBuffer();
    void transRight(GLfloat);
    void transLeft(GLfloat);
    void jump();
    vec3 getLoc();
};

#endif /* defined(___3DBouncingball__Sphere__) */
