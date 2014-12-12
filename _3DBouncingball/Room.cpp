//
//  Room.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/18/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Room.h"

static GLuint Texture;

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
    Texture = loadBMP_custom(filename);
}


void Room::drawCube(mat4 M)
{
    
    // Bind our texture in Texture Unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture);
    
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
            drawCube(M);
        }
    }
    // Top Wall
    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i <= 4; i++) {
            mat4 transMatrix = Translate(i, 4.0f, z*-1);
            mat4 M = transMatrix * scaleMatrix ;
            drawCube(M);
        }
    }

    // Left Wall
    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i < 4; i++) {
            mat4 rotateZ = RotateZ(90);
            mat4 transMatrix = Translate(-4.0f, 1*i, z*-1);
            mat4 M = transMatrix * scaleMatrix * rotateZ ;
            drawCube(M);
        }
    }
    // Right Wall
    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i < 4; i++) {
            mat4 rotateZ = RotateZ(90);
            mat4 transMatrix = Translate(4.0f, 1*i, z*-1);
            mat4 M = transMatrix * scaleMatrix * rotateZ ;
            drawCube(M);
        }
    }
    
    // Front Wall
    for (int z = -4; z < 4; z++) {
        for (int i = -4; i < 4; i++) {
            mat4 transMatrix = Translate(i, z, -WALL_DEPTH);
            mat4 M = transMatrix * scaleMatrix ;
            drawCube(M);
        }
    }
    /////// -------------- Generating obsticlas ------------- ///
    
    for (int z = -4; z < 4; z++) {
        for (int i = -4; i < 0; i++) {
            mat4 transMatrix = Translate(i, z, -50);
            mat4 M = transMatrix * scaleMatrix ;
            drawCube(M);
        }
    }
    for (int z = -4; z < 4; z++) {
        for (int i = -4; i < -1; i++) {
            mat4 transMatrix = Translate(i, z, -WALL_DEPTH);
            mat4 M = transMatrix * scaleMatrix ;
            drawCube(M);
        }
    }
    
    for (int z = -4; z <-1; z++) {
        for (int i = -4; i < 4; i++) {
            mat4 transMatrix = Translate(-i, z, -15);
            mat4 M = transMatrix * scaleMatrix ;
            drawCube(M);
        }
    }
}
