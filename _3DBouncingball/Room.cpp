//
//  Room.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/18/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Room.h"

Room::Room()
{
    reset();
}

void Room::reset()
{
    for (int i = 0; i < 8; i ++) {
        for (int j =0; j< 100; j++) {
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

void Room::writeBuffer()
{
    Game::singleton->currentStartPoint = 0;
    drawWall(1,true);
    drawWall(2,false);
    drawWall(3,false);
    drawWall(4,false);
    drawWall(5,false);
}

void Room::drawWall(int wallT,bool frontWall)
{
    int depth = frontWall?4:WALL_DEPTH;
    int width = 4;
    vec4 colors[36];
    int colorId = 0;
    for (int i = frontWall?-depth:depth ; i < depth; i++) {
        for (int j = -4; j < width; j++) {
            mat4 transMatrix;
            if(wallT == 1) {
                transMatrix = Translate(i, j, -100);
                colorId = (int) FRONT_WALL_SCORE[j+4][i].x;
            }
            else if(wallT == 2){
                transMatrix = Translate(j, -4.0f, i*-1);
                colorId =(int) BOTTOM_WALL_SCORE[j+4][i].x;
            }
            else if(wallT == 3) {
                transMatrix = Translate(j, 3.0f, i*-1);
                colorId =(int)  TOP_WALL_SCORE[j+4][i].x;
            }
            else if(wallT == 4) {
                transMatrix = Translate(3.0f, j, i*-1);
                colorId =(int)  RIGHT_WALL_SCORE[j+4][i].x;
            }
            else if(wallT == 5) {
                transMatrix = Translate(-4.0f, j, i*-1);
                colorId =(int)  LEFT_WALL_SCORE[j+4][i].x;
            }
            
            mat4 M = transMatrix * scaleMatrix;
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(Game::singleton->viewMatrixID, 1, GL_TRUE, M);
            
            for (int idC = 0 ; idC < 36; idC++)
                colors[idC] = kDefaultColors[colorId];
            
            GLuint StartVertix = Game::singleton->currentStartPoint * sizeof(vertices);
            glBufferSubData(GL_ARRAY_BUFFER, StartVertix, sizeof(vertices), vertices);
            
            GLuint StartColorVertix = VWALL_OFFSET + (Game::singleton->currentStartPoint *sizeof(colors));
            glBufferSubData(GL_ARRAY_BUFFER,StartColorVertix, sizeof(colors), colors);
            
            Game::singleton->currentStartPoint += 1;
        }
    }
}

//for (float z = 0.0; z < 100; z ++) {
//    for (float i = -4.0; i < 4.0; i++) {
//        singleton->setColorArray(rand() % kNumOfColors);
//        transMatrix = Translate(i, -4.0f, z*-1);
//        M = transMatrix * scaleMatrix * rotYMatrix;
//        // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
//        
//        glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
//        glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
//        glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
//        
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        
//    }
//}
//
//for (float z = 0.0; z < 100; z ++) {
//    for (float i = -4.0; i < 4.0; i++) {
//        singleton->setColorArray(rand() % kNumOfColors);
//        
//        transMatrix = Translate(i, 3.0f, z*-1);
//        
//        M = transMatrix * scaleMatrix * rotYMatrix;
//        
//        glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
//        glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
//        
//        // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
//        glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
//        
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        
//    }
//}
//for (float z = 0.0; z < 100; z ++) {
//    for (float i = -4.0; i < 4.0; i++) {
//        singleton->setColorArray(rand() % kNumOfColors);
//        
//        transMatrix = Translate(3.0f, 1*i, z*-1);
//        
//        M = transMatrix * scaleMatrix * rotYMatrix;
//        glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
//        glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
//        
//        // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
//        glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
//        
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        
//    }
//}
//for (float z = 0.0; z < 100; z ++) {
//    for (float i = -4.0; i < 4.0; i++) {
//        singleton->setColorArray(rand() % kNumOfColors);
//        
//        transMatrix = Translate(-4.0f, 1*i, z*-1);
//        
//        M = transMatrix * scaleMatrix * rotYMatrix;
//        glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
//        glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
//        
//        // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
//        glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
//        
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        
//    }
//}
//
//for (float y = -4.0; y < 4.0; y++) {
//    for (float i = -4.0; i < 4.0; i++) {
//        singleton->setColorArray(rand() % kNumOfColors);
//        transMatrix = Translate(1*i, 1*y, -100);
//        
//        M = transMatrix * scaleMatrix * rotYMatrix;
//        glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
//        glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
//        
//        // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
//        glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
//        
//        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        
//    }
//}
