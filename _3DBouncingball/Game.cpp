//
//  Game.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/15/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Angel.h"
#include "Game.h"


Game *Game::singleton = NULL;

GLuint perspectiveMatrixID, viewMatrixID, modelMatrixID;
double eyeX, eyeY, eyeZ, centerX, centerY, centerZ;

mat4 rotXMatrix;
mat4 rotYMatrix;
mat4 rotZMatrix;
mat4 transMatrix;
mat4 scaleMatrix;
mat4 tempMatrix;
mat4 M;
mat4 V;
mat4 P;

GLfloat theta; // An amount of rotation along one axis
GLfloat scaleAmount; //In case the object is too big or small
using namespace std;
void Game::run(int argc, char **argv)
{
    singleton = this;
    
    timeval t;
    gettimeofday(&t, NULL);
    srand((unsigned)(t.tv_sec * 1000 + t.tv_usec));
    cout << GL_TIME_ELAPSED << endl;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);
    glutInitWindowPosition(100,50);
    glutCreateWindow("3D Bouncing Ball ...");
    
    initMatrices();
    init();
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutIdleFunc(idle);
    glutMainLoop();
}
vec4 colors[36];

void Game::initMatrices()
{
    theta = 0.0f;
    scaleAmount = 1.0f;
    
    rotXMatrix = identity();
    rotYMatrix = identity();
    rotZMatrix = identity();
    transMatrix = identity();
    scaleMatrix = identity();
    tempMatrix = identity();
    
    M = identity();
    V = identity();
    P = identity();
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
    glBufferData(GL_ARRAY_BUFFER, 36*sizeof(vec3) + 36*sizeof(vec4), NULL, GL_STATIC_DRAW);
    
//    glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
//    glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
    
    GLuint vPosition = glGetAttribLocation(program, "vPosition");
    GLuint vColor = glGetAttribLocation(program, "vColor");
    
    perspectiveMatrixID = glGetUniformLocation(program, "mP");
    viewMatrixID = glGetUniformLocation(program, "mV");
    modelMatrixID = glGetUniformLocation(program, "mM");

    glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(vertices)));
    glEnableVertexAttribArray(vPosition);
    glEnableVertexAttribArray(vColor);

    glClearColor(1.0, 1.0, 1.0, 1.0);
    P = Perspective(60.0f, 1.0f, 0.1f, 1000.0f);
    eyeX = 0.3;
    eyeY = 1;
    eyeZ = 8;
    centerX = 0.0;
    centerY = 0;
    centerZ = 0.0;
}

void Game::setColorArray(GLuint id)
{
    for (int i = 0; i < 36; i++) {
        colors[i] = kDefaultColors[id];
    }
}




void Game::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    V = LookAt(vec4(eyeX,eyeY,eyeZ,0), vec4(centerX,centerY,centerZ,0), vec4(0,1,0,0));

    scaleMatrix = Scale(0.5f, 0.5f, 0.5f);
    rotYMatrix = RotateY(0.0);
    transMatrix = Translate(0.0f, 0.0f, 0.0f);
    
//    M = transMatrix * scaleMatrix * rotYMatrix;
    
    // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
//    glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
    glUniformMatrix4fv(viewMatrixID, 1, GL_TRUE, V);
    glUniformMatrix4fv(perspectiveMatrixID, 1, GL_TRUE, P);
//    
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//    glDrawArrays(GL_TRIANGLES, 0, 36);

    for (float z = 0.0; z < 100; z ++) {
        for (float i = -4.0; i < 3.0; i++) {
            singleton->setColorArray(rand() % kNumOfColors);
            
            transMatrix = Translate(i, -4.0f, z*-1);
            
            M = transMatrix * scaleMatrix * rotYMatrix;
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
            
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
            glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);

            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            
        }
    }

    for (float z = 0.0; z < 100; z ++) {
        for (float i = -4.0; i < 3.0; i++) {
            singleton->setColorArray(rand() % kNumOfColors);
            
            transMatrix = Translate(i, 3.0f, z*-1);
            
            M = transMatrix * scaleMatrix * rotYMatrix;
            
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
            glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            
        }
    }
    for (float z = 0.0; z < 100; z ++) {
        for (float i = -4.0; i < 4.0; i++) {
            singleton->setColorArray(rand() % kNumOfColors);
            
            transMatrix = Translate(3.0f, 1*i, z*-1);
            
            M = transMatrix * scaleMatrix * rotYMatrix;
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
            glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            
        }
    }
    for (float z = 0.0; z < 100; z ++) {
        for (float i = -4.0; i < 4.0; i++) {
            singleton->setColorArray(rand() % kNumOfColors);
            
            transMatrix = Translate(-4.0f, 1*i, z*-1);
            
            M = transMatrix * scaleMatrix * rotYMatrix;
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
            glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            
        }
    }
    
    for (float y = -4.0; y < 4.0; y++) {
        for (float i = -4.0; i < 4.0; i++) {
            singleton->setColorArray(rand() % kNumOfColors);
            transMatrix = Translate(1*i, 1*y, -100);
            
            M = transMatrix * scaleMatrix * rotYMatrix;
            glBufferSubData(GL_ARRAY_BUFFER, 0, 36*sizeof(vec3), vertices);
            glBufferSubData(GL_ARRAY_BUFFER, 36*sizeof(vec3), 36*sizeof(vec4), colors);
            
            // passing the Matrices IDs to the shaders .... 1 -> Number of Matrices
            glUniformMatrix4fv(modelMatrixID, 1, GL_TRUE, M);
            
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            
        }
    }
    glutSwapBuffers();
}

void Game::reset()
{
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