
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


const int WINDOWS_WIDTH = 1280;
const int WINDOWS_HEIGHT = 1024;

const int SIDE_WALL_WIDTH = 100;
const int FRONT_WALL_WIDTH = 10;
const int WALL_HIGHT = 10;

const int SQR_SIZE = 10;

const int CNTotalSQRPoints = 4;

const int CNSideWallSquares =(SIDE_WALL_WIDTH * WALL_HIGHT) / (SQR_SIZE * SQR_SIZE);
const int CNFrontWallSquares =(FRONT_WALL_WIDTH * WALL_HIGHT) / (SQR_SIZE * SQR_SIZE);

const int CNTotalNumberOfSquares = 4*CNSideWallSquares + CNFrontWallSquares;

const int TotalNumOFSquaresInWall = 100;

const int CNTotalPoints = 100;

const int numberOfVertices = 9;

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


//static vec4 colors[] = {
//    vec4(0.583f,  0.771f,  0.014f, 1.0f),
//    vec4(0.609f,  0.115f,  0.436f, 1.0f),
//    vec4(0.327f,  0.483f,  0.844f, 1.0f),
//    vec4(0.822f,  0.569f,  0.201f, 1.0f),
//    vec4(0.435f,  0.602f,  0.223f, 1.0f),
//    vec4(0.310f,  0.747f,  0.185f, 1.0f),
//    vec4(0.597f,  0.770f,  0.761f, 1.0f),
//    vec4(0.559f,  0.436f,  0.730f, 1.0f),
//    vec4(0.359f,  0.583f,  0.152f, 1.0f),
//    vec4(0.483f,  0.596f,  0.789f, 1.0f),
//    vec4(0.559f,  0.861f,  0.639f, 1.0f),
//    vec4(0.195f,  0.548f,  0.859f, 1.0f),
//    vec4(0.014f,  0.184f,  0.576f, 1.0f),
//    vec4(0.771f,  0.328f,  0.970f, 1.0f),
//    vec4(0.406f,  0.615f,  0.116f, 1.0f),
//    vec4(0.676f,  0.977f,  0.133f, 1.0f),
//    vec4(0.971f,  0.572f,  0.833f, 1.0f),
//    vec4(0.140f,  0.616f,  0.489f, 1.0f),
//    vec4(0.997f,  0.513f,  0.064f, 1.0f),
//    vec4(0.945f,  0.719f,  0.592f, 1.0f),
//    vec4(0.543f,  0.021f,  0.978f, 1.0f),
//    vec4(0.279f,  0.317f,  0.505f, 1.0f),
//    vec4(0.167f,  0.620f,  0.077f, 1.0f),
//    vec4(0.347f,  0.857f,  0.137f, 1.0f),
//    vec4(0.055f,  0.953f,  0.042f, 1.0f),
//    vec4(0.714f,  0.505f,  0.345f, 1.0f),
//    vec4(0.783f,  0.290f,  0.734f, 1.0f),
//    vec4(0.722f,  0.645f,  0.174f, 1.0f),
//    vec4(0.302f,  0.455f,  0.848f, 1.0f),
//    vec4(0.225f,  0.587f,  0.040f, 1.0f),
//    vec4(0.517f,  0.713f,  0.338f, 1.0f),
//    vec4(0.053f,  0.959f,  0.120f, 1.0f),
//    vec4(0.393f,  0.621f,  0.362f, 1.0f),
//    vec4(0.673f,  0.211f,  0.457f, 1.0f),
//    vec4(0.820f,  0.883f,  0.371f, 1.0f),
//    vec4(0.982f,  0.099f,  0.879f, 1.0f)
//};
//

#endif
