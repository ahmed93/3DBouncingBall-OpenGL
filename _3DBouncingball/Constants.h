
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

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 1024;

const int WALL_DEPTH = 300;
const int WALL_WIDTH = 8;

// Side Walls
const int SIDEWALLS_CUBES = 4 * WALL_WIDTH * WALL_DEPTH;
//const int CTotalVOfSideWall = SIDEWALLS_CUBES;
const int CTotalVOfSideWall_OFFSET = SIDEWALLS_CUBES * sizeof(vertices);

// Front Wall
const int FRONTWALL_CUBES = WALL_WIDTH * WALL_WIDTH;
//const int CTotalVOfFrontWall = FRONTWALL_CUBES;
const int CTotalVOfFrontWall_OFFSET = FRONTWALL_CUBES * sizeof(vertices);

const int CTotalNumberOfCubes = FRONTWALL_CUBES + SIDEWALLS_CUBES;
const int CTotalNumberOfCubesVertices = (SIDEWALLS_CUBES + FRONTWALL_CUBES) * 36;

const int CTotal_OFFSET_OfVetices = CTotalVOfSideWall_OFFSET + CTotalVOfFrontWall_OFFSET;
const int CTotal_OFFSET_OfColors = CTotalNumberOfCubesVertices * sizeof(vec4);

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


#endif
