//
//  Sphere.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/25/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Sphere.h"
#include "objloader.hpp"
#include <vector>

static vector<vec3> sVertices;
static vector<vec2> sUVS;
static vector<vec3> sNormals;
static GLuint Texture;
static GLfloat x = 0,y = -3;
bool downball = false;
Sphere::Sphere()
{
    // Read our .obj file
    loadOBJ("cube.obj", sVertices, sUVS, sNormals);
}


void Sphere::setTexture(char* filename)
{
    Texture = loadBMP_custom("box.bmp");
}

void Sphere::drawS(mat4 M)
{
    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture);
    
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(GameSingleton->TextureID, 0);
    
    mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
    mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),vec4(0,1,0,0));
    glBufferSubData(GL_ARRAY_BUFFER, 0, sVertices.size() * sizeof(vec3), &sVertices[0]);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sUVS.size() * sizeof(vec2), &sUVS[0]);
    
    // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
    glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
    glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
    glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, sVertices.size());
}


void Sphere::transRight(GLfloat value)
{
    if (x < 2.4)
        x += value;
}

void Sphere::transLeft(GLfloat value)
{
    if (x > -2.4)
        x -= value;
}

int yincrement = 0;
int presentage = 0.2;
bool down = false;

void Sphere::jump()
{
    
    if(y<= 0 && downball==false){
        y++;
    }else if(y > -3)
    {
        downball = true;
        y--;
    }else
    {
        GameSingleton->setJump(false);
        downball = false;
    }
    
}

void Sphere::writeBuffer()
{
    mat4 trans = Translate(x, y, GameSingleton->eyeZ-3);
    //    mat4 rot = RotateZ(30);
    drawS(trans * 2*scaleMatrix);
}

vec3 Sphere::getLoc()
{
    return vec3(x,y,GameSingleton->eyeZ-3);
}
