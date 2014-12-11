//
//  Game.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/15/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Angel.h"
#include "Game.h"
#include "Room.H"

Game *Game::singleton = NULL;

mat4 rotXMatrix;
mat4 rotYMatrix;
mat4 rotZMatrix;
mat4 transMatrix;
mat4 tempMatrix;
mat4 M;
mat4 V;
mat4 P;

GLfloat theta; // An amount of rotation along one axis
GLfloat scaleAmount; //In case the object is too big or small

void Game::run(int argc, char **argv)
{
    currentStartPoint = 0;
    singleton = this;
    singleton->room = new Room();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100,50);
    glutCreateWindow("3D Bouncing Ball ...");
    initMatrices();
    init();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutIdleFunc(idle);
    glutMainLoop();
}

void Game::initMatrices()
{
    theta = 0.0f;
    scaleAmount = 1.0f;
    
    rotXMatrix = identity();
    rotYMatrix = identity();
    rotZMatrix = identity();
    transMatrix = identity();
    tempMatrix = identity();
    
    M = identity();
    V = identity();
    P = identity();

    eyeX = 1;
    eyeY = 1;
    eyeZ = 5;
    centerX = 1;
    centerY = 1;
    centerZ = -1000;
}

void Game::init()
{
    // init The Program Shader ID
    GLuint program = InitShader("vshader.glsl", "fshader.glsl");
    
    // creating Vertex Array Objects
    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);
    
    // creating Vertex Buffer Objects
    GLuint vboID;
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, CTotal_OFFSET_OfVetices  + CTotal_OFFSET_OfColors, NULL, GL_STATIC_DRAW);
    
    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    GLuint vColor = glGetAttribLocation(program, "vColor");
    
    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(CTotal_OFFSET_OfVetices));
    glEnableVertexAttribArray(vPosition);
    glEnableVertexAttribArray(vColor);
    
    perspectiveMatrixID = glGetUniformLocation(program, "mP");
    viewMatrixID = glGetUniformLocation(program, "mV");
    modelMatrixID = glGetUniformLocation(program, "mM");
    
    glClearColor(0.9, 0.9, 0.9, 1.0);
}

void Game::reset()
{
    eyeX = 1;
    eyeY = 1;
    eyeZ = 5;
    centerX = 1;
    centerY = 1;
    centerZ = -1000;
    singleton->room->reset();
}

void Game::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    singleton->room->writeBuffer();
    
    glutSwapBuffers();
}

void Game::keyboard(unsigned char key, int x, int y)
{
    switch (key){
        case GLUT_KEY_DOWN:
            singleton->eyeX -= 0.1 * (singleton->centerX - singleton->eyeX);
            singleton->eyeZ -= 0.1 * (singleton->centerZ - singleton->eyeZ);
            break;
        case GLUT_KEY_UP:
//            singleton->eyeX += 0.1 * (singleton->centerX - singleton->eyeX);
            singleton->eyeZ --;
            ;//* (singleton->centerZ - singleton->eyeZ);
            break;
        case 'r':
            singleton->reset();
            break;
    }
}

void Game::special(int key, int x, int y)
{
    keyboard(key, x, y);
}

void Game::idle()
{
    usleep(20);
    glutPostRedisplay();
}

void Game::game_over()
{
    is_game_over = true;
}