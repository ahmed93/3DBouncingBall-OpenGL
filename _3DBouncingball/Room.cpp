//
//  Room.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/18/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Room.h"

#define GameSingleton Game::singleton

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

void Room::writeBuffer()
{
        for (int z = 0; z < WALL_DEPTH; z++) {
            for (int i = -4; i < 4; i++) {
                vec4 colors[36];
                
                for (int idC = 0 ; idC < 36; idC++){
                    int colorID = (int)BOTTOM_WALL_SCORE[i+4][z].x;
                    colors[idC] = kDefaultColors[colorID];
                }
                
                mat4 transMatrix = Translate(i, -4.0f, z*-1);
                
                mat4 M = transMatrix * scaleMatrix ;
                mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
                mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),
                                vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),
                                vec4(0,1,0,0));
    
                // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
                glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
                glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
                glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
                
                glBufferSubData(GL_ARRAY_BUFFER, 0, 36 * sizeof(vec3), vertices);

                glBufferSubData(GL_ARRAY_BUFFER, CTotal_OFFSET_OfVetices, sizeof(colors), colors);
    
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
            }
        }
    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i < 4; i++) {
            vec4 colors[36];
            
            for (int idC = 0 ; idC < 36; idC++){
                int colorID = (int)TOP_WALL_SCORE[i+4][z].x;
                colors[idC] = kDefaultColors[colorID];
            }
            
            mat4 transMatrix = Translate(i, 4.0f, z*-1);
            
            mat4 M = transMatrix * scaleMatrix ;
            mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
            mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),
                            vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),
                            vec4(0,1,0,0));
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
            glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
            glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
            
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36 * sizeof(vec3), vertices);
            
            glBufferSubData(GL_ARRAY_BUFFER, CTotal_OFFSET_OfVetices, sizeof(colors), colors);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
        }
    }

    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i < 4; i++) {
            vec4 colors[36];
            
            for (int idC = 0 ; idC < 36; idC++){
                int colorID = (int)LEFT_WALL_SCORE[i+4][z].x;
                colors[idC] = kDefaultColors[colorID];
            }
            
            mat4 transMatrix = Translate(-4.0f, 1*i, z*-1);
            
            mat4 M = transMatrix * scaleMatrix ;
            mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
            mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),
                            vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),
                            vec4(0,1,0,0));
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
            glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
            glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
            
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36 * sizeof(vec3), vertices);
            
            glBufferSubData(GL_ARRAY_BUFFER, CTotal_OFFSET_OfVetices, sizeof(colors), colors);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
        }
    }
    for (int z = 0; z < WALL_DEPTH; z++) {
        for (int i = -4; i < 4; i++) {
            vec4 colors[36];
            
            for (int idC = 0 ; idC < 36; idC++){
                int colorID = (int)RIGHT_WALL_SCORE[i+4][z].x;
                colors[idC] = kDefaultColors[colorID];
            }
            
            mat4 transMatrix = Translate(4.0f, 1*i, z*-1);
            
            mat4 M = transMatrix * scaleMatrix ;
            mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
            mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),
                            vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),
                            vec4(0,1,0,0));
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
            glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
            glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
            
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36 * sizeof(vec3), vertices);
            
            glBufferSubData(GL_ARRAY_BUFFER, CTotal_OFFSET_OfVetices, sizeof(colors), colors);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
        }
    }
    
    
    for (int z = -4; z < 4; z++) {
        for (int i = -4; i < 4; i++) {
            vec4 colors[36];
            
            for (int idC = 0 ; idC < 36; idC++){
                int colorID = (int)FRONT_WALL_SCORE[i+4][z+4].x;
                colors[idC] = kDefaultColors[colorID];
            }
            
            mat4 transMatrix = Translate(i, z, -WALL_DEPTH);
            
            mat4 M = transMatrix * scaleMatrix ;
            mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
            mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),
                            vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),
                            vec4(0,1,0,0));
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
            glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
            glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
            
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36 * sizeof(vec3), vertices);
            
            glBufferSubData(GL_ARRAY_BUFFER, CTotal_OFFSET_OfVetices, sizeof(colors), colors);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
            //                Game::singleton->currentStartPoint += 1;
        }
    }
    
    for (int z = -4; z < 4; z++) {
        for (int i = -4; i < 0; i++) {
            vec4 colors[36];
            
            for (int idC = 0 ; idC < 36; idC++){
                int colorID = (int)FRONT_WALL_SCORE[i+4][z+4].x;
                colors[idC] = kDefaultColors[colorID];
            }
            
            mat4 transMatrix = Translate(i, z, -50);
            
            mat4 M = transMatrix * scaleMatrix ;
            mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
            mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),
                            vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),
                            vec4(0,1,0,0));
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
            glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
            glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
            
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36 * sizeof(vec3), vertices);
            
            glBufferSubData(GL_ARRAY_BUFFER, CTotal_OFFSET_OfVetices, sizeof(colors), colors);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
            //                Game::singleton->currentStartPoint += 1;
        }
    }
    for (int z = -4; z < 4; z++) {
        for (int i = -4; i < -1; i++) {
            vec4 colors[36];
            
            for (int idC = 0 ; idC < 36; idC++){
                int colorID = (int)FRONT_WALL_SCORE[i+4][z+4].x;
                colors[idC] = kDefaultColors[colorID];
            }
            
            mat4 transMatrix = Translate(i, z, -WALL_DEPTH);
            
            mat4 M = transMatrix * scaleMatrix ;
            mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
            mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),
                            vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),
                            vec4(0,1,0,0));
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
            glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
            glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
            
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36 * sizeof(vec3), vertices);
            
            glBufferSubData(GL_ARRAY_BUFFER, CTotal_OFFSET_OfVetices, sizeof(colors), colors);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
            // Game::singleton->currentStartPoint += 1;
        }
    }
    
    for (int z = -4; z <-1; z++) {
        for (int i = -4; i < 4; i++) {
            vec4 colors[36];
            
            for (int idC = 0 ; idC < 36; idC++){
                int colorID = (int)FRONT_WALL_SCORE[i+4][z+4].x;
                colors[idC] = kDefaultColors[colorID];
            }
            
            mat4 transMatrix = Translate(-i, z, -15);
            
            mat4 M = transMatrix * scaleMatrix ;
            mat4 P = Perspective(80.0f, 1.0f, 0.1f, WALL_DEPTH);
            mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),
                            vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),
                            vec4(0,1,0,0));
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
            glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
            glUniformMatrix4fv(GameSingleton->modelMatrixID, 1, GL_TRUE, M);
            
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36 * sizeof(vec3), vertices);
            
            glBufferSubData(GL_ARRAY_BUFFER, CTotal_OFFSET_OfVetices, sizeof(colors), colors);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 36);
            //                Game::singleton->currentStartPoint += 1;
        }
    }

}

//void Room::drawWall(int wallT,bool frontWall)
//{
//    int depth = frontWall?4:WALL_DEPTH;
//    int width = WALL_WIDTH/2;
//    for (int i = frontWall?-4:0 ; i < depth; i++) {
//        for (int j = -4; j < 4; j++) {
//            mat4 transMatrix;
//            vec4 colors[36];
//            int colorId = 0;
//            if(wallT == 1) {// Front wall
//                transMatrix = Translate(i, j, -1.0f * WALL_DEPTH);
//                colorId = (int) FRONT_WALL_SCORE[j+width][i].x;
//            }
//            else if(wallT == 2){ // Bottom wall
//                transMatrix = Translate(j * 1.0f, -width * 1.0f, i * -1.0f);
//                colorId =(int) BOTTOM_WALL_SCORE[j+width][i].x;
//            }
//            else if(wallT == 3) {// Top wall
//                transMatrix = Translate(j* 1.0f,  width * 1.0f, i * -1.0f);
//                colorId =(int)  TOP_WALL_SCORE[j+width][i].x;
//            }
//            else if(wallT == 4) {// RIght wall
//                transMatrix = Translate( width * 1.0f, j * 1.0f, i * -1.0f);
//                colorId =(int)  RIGHT_WALL_SCORE[j+width][i].x;
//            }
//            else if(wallT == 5) {// Left wall
//                transMatrix = Translate( -width * 1.0f, j * 1.0f, i * -1.0f);
//                colorId =(int)  LEFT_WALL_SCORE[j+width][i].x;
//            }
//            
//            for (int idC = 0 ; idC < 36; idC++)
//                colors[idC] = kDefaultColors[colorId];
//        
//            mat4 M = transMatrix * scaleMatrix;
//            mat4 P = Perspective(80.0f, 1.0f, 0.1f, 100.0f);
//            mat4 V = LookAt(vec4(GameSingleton->eyeX,GameSingleton->eyeY,GameSingleton->eyeZ,0),
//                            vec4(GameSingleton->centerX,GameSingleton->centerY,GameSingleton->centerZ,0),
//                            vec4(0,1,0,0));
//            cout << colorId << endl;
//            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
//            glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, M);
//            glUniformMatrix4fv(GameSingleton->viewMatrixID, 1, GL_TRUE, V);
//            glUniformMatrix4fv(GameSingleton->perspectiveMatrixID, 1, GL_TRUE, P);
//            
//            GLuint currentCount = GameSingleton->currentStartPoint;
//            
//            GLuint StartVertix = currentCount * sizeof(vertices);
//            glBufferSubData(GL_ARRAY_BUFFER, StartVertix, sizeof(vertices), vertices);
//            
//////
////            GLuint StartColorVertix = CTotal_OFFSET_OfVetices + (currentCount * sizeof(colors));
////            glBufferSubData(GL_ARRAY_BUFFER,StartColorVertix, sizeof(colors), colors);
//            
//            GameSingleton->currentStartPoint += 1;
//        }
//    }
//}

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
