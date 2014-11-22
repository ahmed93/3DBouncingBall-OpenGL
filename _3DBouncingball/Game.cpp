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

double eyeX, eyeY, eyeZ, centerX, centerY, centerZ;

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
using namespace std;
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
    
    eyeX = 0.3;
    eyeY = 1;
    eyeZ = 8;
    centerX = 0.0;
    centerY = 0;
    centerZ = 0.0;
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
    glBufferData(GL_ARRAY_BUFFER, WALL_TOTAL_OFFSET, NULL, GL_STATIC_DRAW);
    
    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    GLuint vColor = glGetAttribLocation(program, "vColor");
    
    perspectiveMatrixID = glGetUniformLocation(program, "mP");
    viewMatrixID = glGetUniformLocation(program, "mV");
    modelMatrixID = glGetUniformLocation(program, "mM");

    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(VWALL_OFFSET));
    glEnableVertexAttribArray(vPosition);
    glEnableVertexAttribArray(vColor);
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void Game::reset()
{
    P = Perspective(60.0f, 1.0f, 0.1f, 1000.0f);
    V = LookAt(vec4(eyeX,eyeY,eyeZ,0), vec4(centerX,centerY,centerZ,0), vec4(0,1,0,0));
    glUniformMatrix4fv(singleton->viewMatrixID, 1, GL_TRUE, V);
    glUniformMatrix4fv(singleton->perspectiveMatrixID, 1, GL_TRUE, P);
    singleton->room->writeBuffer();
}

void Game::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    V = LookAt(vec4(eyeX,eyeY,eyeZ,0), vec4(centerX,centerY,centerZ,0), vec4(0,1,0,0));
    glUniformMatrix4fv(singleton->viewMatrixID, 1, GL_TRUE, V);
    singleton->reset();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, TotalNumberOfWallVertices);
    glutSwapBuffers();
}

void Game::keyboard(unsigned char key, int x, int y)
{
    switch (key){
        case GLUT_KEY_DOWN:
            eyeX -= 0.1 * (centerX - eyeX);
            eyeZ -= 0.1 * (centerZ - eyeZ);
            break;
        case GLUT_KEY_UP:
            eyeX += 0.1 * (centerX - eyeX);
            eyeZ += 0.1 * (centerZ - eyeZ);
            break;
        case GLUT_KEY_LEFT:
            eyeZ-= 0.1;
            break;
        case GLUT_KEY_RIGHT:
            eyeZ+= 0.1;
            break;
        case 'w':
            eyeY+= 0.1;
            break;
        case 's':
            eyeY -= 0.1;
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