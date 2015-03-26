
//
//  Room.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/18/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Room.h"
#include "Sphere.h"

static GLuint Texture[5];
static GLfloat movies_wall_counter = 0, value = 0;
int i = 0;
int i1 = 0;
int i2 = 0;
int ii = 0;

Room::Room()
{
    reset();
}

void Room::reset()
{
    for (int i = 0; i < 8; i ++) {
        for (int j =0; j< WALL_DEPTH; j++) {
            int randID = rand() % kNumOfColors;
            TOP_WALL_SCORE[i][j] = vec2(randID, setScore(randID));
            randID = rand() % kNumOfColors;
            BOTTOM_WALL_SCORE[i][j] = vec2(randID, setScore(randID));
            randID = rand() % kNumOfColors;
            LEFT_WALL_SCORE[i][j] = vec2(randID, setScore(randID));
            randID = rand() % kNumOfColors;
            RIGHT_WALL_SCORE[i][j] = vec2(randID, setScore(randID));
        }
        for (int j =0; j< 8; j++) {
            int randID = rand() % kNumOfColors;
            FRONT_WALL_SCORE[i][j] = vec2(randID, setScore(randID));
        }
    }
}

int Room::setScore(int colorID)
{
    int score = 0;
    switch (colorID) {
        case 0:
            score = 2;
            break;
        case 1:
            score = 20;
            break;
        case 2:
            score = -30;
            break;
        case 3:
            score = 22;
            break;
        case 4:
            score = 10;
            break;
        case 5:
            score = 50;
            break;
        case 6:
            score = -100;
            break;
        case 7:
            score = -10;
            break;
        case 8:
            score = 35;
            break;
        case 9:
            score = 55;
            break;
        default:
            score = 1;
            break;
    }
    return score;
}

void Room::setTexture(char* filename)
{
    Texture[0] = loadBMP_custom(filename);
    Texture[1] = loadBMP_custom("boxDanger.bmp");
    Texture[2] = loadBMP_custom("grass.bmp");
}


void Room::drawCube(mat4 M, GLuint textureIndex)
{
    
    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture[textureIndex]);
    
    // Set our "myTextureSampler" sampler to user Texture Unit 0
    glUniform1i(GameSingleton->TextureID, 0);
    
    mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
    mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),vec4(0,1,0,0));
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(uv_buffer_data), uv_buffer_data);
    
    // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
    glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
    glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
    glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
    
}


void Room::writeBuffer()
{
    // Bottom Wall
    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i < 4; i++) {
            mat4 transMatrix = Translate(i, -4.0f, z*-1);
            mat4 M = transMatrix * scaleMatrix ;
            drawCube(M, 2);
        }
    }
    // Top Wall
    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i <= 4; i++) {
            mat4 transMatrix = Translate(i, 4.0f, z*-1);
            mat4 M = transMatrix * scaleMatrix ;
            drawCube(M, 0);
        }
    }
    
    // Left Wall
    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i < 4; i++) {
            mat4 rotateZ = RotateZ(90);
            mat4 transMatrix = Translate(-4.0f, 1*i, z*-1);
            mat4 M = transMatrix * scaleMatrix * rotateZ ;
            drawCube(M, 0);
        }
    }
    // Right Wall
    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i < 4; i++) {
            mat4 rotateZ = RotateZ(90);
            mat4 transMatrix = Translate(4.0f, 1*i, z*-1);
            mat4 M = transMatrix * scaleMatrix * rotateZ ;
            drawCube(M, 0);
        }
    }
    
    // Front Wall
    for (int z = -4; z < 4; z++) {
        for (int i = -4; i < 4; i++) {
            mat4 transMatrix = Translate(i, z, -WALL_DEPTH);
            mat4 M = transMatrix * scaleMatrix ;
            drawCube(M, 0);
        }
    }
    /////// -------------- Generating obsticlas ------------- ///
    
    for (int y = -4; y < 4; y++) {
        for (int x = -3 ; x < -2 ; x++) {
            mat4 transMatrix = Translate(x+value, y, -50);
            mat4 M = transMatrix * scaleMatrix ;
            drawCube(M, 1);
        }
    }
    for (int y = -4; y < 4; y++) {
        
        OBS(1, y, -5, 0);
        OBS(0, y, -15, 0);
        OBS_B(-3, y, -15, 1);
        OBS(1, y, -20, 0);
        OBS_B(-1, y, -30, 1);
        OBS(-2, y, -35, 0);
        OBS_B(-1, y, -40, 1);
        OBS(2, y, -40, 0);
        OBS_B(-1, y, -55, 1);
        OBS(0, y, -55, 0);
        OBS(2, y, -58, 0);
        OBS_B(-1, y, -62, 1);
        OBS_B(-1, y, -70, 1);
        OBS(-1, y, -75, 0);
        OBS(1, y, -80, 0);
        OBS_B(-1, y, -100, 1);
        OBS(0, y, -100, 0);
        OBS(-2, y, -115, 0);
        OBS_B(-1, y, -130, 1);
        OBS_B(-1, y, -150, 1);
        OBS(0, y, -150, 0);
        OBS(2, y, -165, 0);
        OBS_B(-1, y, -170, 1);
        OBS(-1, y, -175, 0);
        OBS_B(-1, y, -185, 1);
        OBS(1, y, -195, 0);
        OBS_B(-1, y, -215, 1);
        OBS(-0, y, -215, 0);
        OBS_B(-1, y, -225, 1);
        OBS(2, y, -225, 0);
        OBS(-1, y, -235, 0);
        OBS_B(-1, y, -255, 1);
        OBS(0, y, -265, 0);
        OBS_B(-1, y, -280, 1);
        OBS(1, y, -285, 0);
        OBS_B(-1, y, -290, 1);
        
    }
    if (movies_wall_counter > 5) {
        movies_wall_counter *= -1;
        value*=-1;
    }
    
    movies_wall_counter+= 0.1;
    value=0.1+movies_wall_counter;
    
    i =0;
    ii = 0;
}

void Room::OBS(int xd, int yd, int zd, int type){
    if(type == 0){
        mat4 transMatrix = Translate(xd, yd, zd);
        mat4 M = transMatrix * scaleMatrix ;
        drawCube(M, 1);
        OBS_V_WALL_SCORE[i++]= vec3(xd, yd, zd);
    }else{
        mat4 transMatrix = Translate(xd, yd, zd);
        mat4 M = transMatrix * scaleMatrix ;
        drawCube(M, 1);
        OBS_H_WALL_SCORE[ii++]= vec3(xd, yd, zd);
    }
}

void Room::OBS_B(int xd, int yd, int zd, int type)
{
//    for (int x = -3 ; x < -2 ; x++)
        OBS(yd, -3, zd, type);
}


void Room::coll_ded(){
    vec3 sploc = sphere->getLoc();
//    PrintC(sploc);
    if (OBS_V_WALL_SCORE[i1].z ==sploc.z)
    {
        if (sploc.x == OBS_V_WALL_SCORE[i1].x)
        {
//            std::cout<<"L " << i1 << std::endl;
            GameSingleton->score -= 10;
            std::cout<<"Current Score: " << GameSingleton->score << std::endl;
        }
        i1++;
    }
    
    if (OBS_H_WALL_SCORE[i2].z==sploc.z)
    {
        if (OBS_H_WALL_SCORE[i2].y == -3)
        {
//            std::cout<<"Bottom " << i2 << std::endl;
            GameSingleton->score -= 5;
            std::cout<<"Current Score: " << GameSingleton->score << std::endl;
        }
        i2++;
    }
}
