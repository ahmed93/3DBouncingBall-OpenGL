
//  Constants.h
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/15/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#ifndef _3DBouncingball_Constants_h
#define _3DBouncingball_Constants_h

#include "Angel.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


const mat4 scaleMatrix = Scale(0.5f, 0.5f, 0.5f);

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 1024;

const int WALL_DEPTH = 100;
const int WALL_WIDTH = 8;

const int RIGHT_WALL_VERTICES = WALL_DEPTH *  WALL_WIDTH * 36;
const int LEFT_WALL_VERTICES = WALL_DEPTH *  WALL_WIDTH * 36;
const int TOP_WALL_VERTICES = WALL_DEPTH *  WALL_WIDTH * 36;
const int BOTTOM_WALL_VERTICES = WALL_DEPTH *  WALL_WIDTH * 36;
const int FRONT_WALL_VERTICES = WALL_WIDTH * WALL_WIDTH * 36;

const int TotalNumberOfWallVertices = RIGHT_WALL_VERTICES + LEFT_WALL_VERTICES + TOP_WALL_VERTICES + BOTTOM_WALL_VERTICES + FRONT_WALL_VERTICES;
const int TotalNumberOfWallVerticesColors = TotalNumberOfWallVertices;

const int WALL_OFFSET = 36*sizeof(vec3) + 36*sizeof(vec4);
const int VWALL_OFFSET = TotalNumberOfWallVertices*sizeof(vec3);

//const int BeginPoints;
//const int kNumOfTetrominoPoints = 16;

const int kNumOfColors = 10;
const vec4 kDefaultColors[kNumOfColors] =
{
    vec4(0.37f, 0.62f, 0.95f, 1.0f), // blue
    vec4(0.39f, 0.84f, 0.29f, 1.0f), // green
    vec4(0.95f, 0.28f, 0.25f, 1.0f), // red
    vec4(0.75f, 0.37f, 0.99f, 1.0f), // purple
    vec4(0.97f, 0.57f, 0.22f, 1.0f), // orange
    vec4(0.99f, 0.37f, 0.61f, 1.0f), // pink
    vec4(0.17f, 0.60f, 0.90f, 1.0f),
    vec4(0.47f, 0.42f, 0.20f, 1.0f),
    vec4(0.27f, 0.19f, 0.30f, 1.0f),
    vec4(0.07f, 0.24f, 0.60f, 1.0f)
};

const vec3 vertices[] = {
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(-1.0f,-1.0f, 1.0f),
    vec3(-1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f,-1.0f),
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(-1.0f, 1.0f,-1.0f),
    vec3(1.0f,-1.0f, 1.0f),
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(1.0f,-1.0f,-1.0f),
    vec3(1.0f, 1.0f,-1.0f),
    vec3(1.0f,-1.0f,-1.0f),
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(-1.0f, 1.0f, 1.0f),
    vec3(-1.0f, 1.0f,-1.0f),
    vec3(1.0f,-1.0f, 1.0f),
    vec3(-1.0f,-1.0f, 1.0f),
    vec3(-1.0f,-1.0f,-1.0f),
    vec3(-1.0f, 1.0f, 1.0f),
    vec3(-1.0f,-1.0f, 1.0f),
    vec3(1.0f,-1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f,-1.0f,-1.0f),
    vec3(1.0f, 1.0f,-1.0f),
    vec3(1.0f,-1.0f,-1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f,-1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f,-1.0f),
    vec3(-1.0f, 1.0f,-1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(-1.0f, 1.0f,-1.0f),
    vec3(-1.0f, 1.0f, 1.0f),
    vec3(1.0f, 1.0f, 1.0f),
    vec3(-1.0f, 1.0f, 1.0f),
    vec3(1.0f,-1.0f, 1.0f)
};
#endif
