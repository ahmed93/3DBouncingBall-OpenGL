//
//  Room.h
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/18/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#ifndef ___3DBouncingball__Room__
#define ___3DBouncingball__Room__

#include "Constants.h"
#include "Game.h"
#include "Texture.h"
#include "Sphere.h"

class Sphere;
class Room {
private:
    vec2 FRONT_WALL_SCORE[WALL_WIDTH][WALL_WIDTH];
    vec2 BOTTOM_WALL_SCORE[WALL_WIDTH][WALL_DEPTH];
    vec2 TOP_WALL_SCORE[WALL_WIDTH][WALL_DEPTH];
    vec2 RIGHT_WALL_SCORE[WALL_WIDTH][WALL_DEPTH];
    vec2 LEFT_WALL_SCORE[WALL_WIDTH][WALL_DEPTH];
    vec3 OBS_V_WALL_SCORE[25];
    vec3 OBS_H_WALL_SCORE[25];

    
protected:
    void drawWall(mat4);
    void drawWall(int wallT,bool frontWall);
    int setScore(int colorID);
    void drawCube(mat4, GLuint);
    void OBS(int xd, int yd, int zd, int type);
    void OBS_B(int xd, int yd, int zd, int type);
    
public:    
    Room();
    Sphere* sphere;
    void init();
    void reset();
    void setTexture(char*);
    void writeBuffer();
    void coll_ded();
};


#endif /* defined(___3DBouncingball__Room__) */
