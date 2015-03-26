
//
//  Game.cpp
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/15/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#include "Game.h"
#include "Room.h"
#include "Texture.h"

#include "AudioPlayer.h"

Game *Game::singleton = NULL;

mat4 rotXMatrix;
mat4 rotYMatrix;
mat4 rotZMatrix;
mat4 transMatrix;
mat4 tempMatrix;
mat4 M;
mat4 V;
mat4 P;
bool start, jump;
GLuint uvbuffer;
GLfloat theta;
GLfloat scaleAmount;

void Game::run(int argc, char **argv)
{
    currentStartPoint = 0;
    singleton = this;
    singleton->sphere = new Sphere();
    singleton->room = new Room();
    singleton->room->sphere = singleton->sphere;
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
    glutMouseFunc(mouse);
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
    eyeZ = 3;
    centerX = 1;
    centerY = 1;
    centerZ = -1000;
}

void print(int x, int y, char *string)
{
    int len, i;
    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
}
//AudioPlayer* ap;
//void Game::playMusic()
//{
//    ap = AudioPlayer::file("music.mp3");
//    if(!ap) {
//        std::cerr << "Error loading audio" << std::endl;
//    }else
//        ap->play();
//}

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
    glBufferData(GL_ARRAY_BUFFER, 36*sizeof(vec3) + 36*sizeof(vec2), NULL, GL_DYNAMIC_DRAW);

    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(vertices)));
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    // Get a handle for our "myTextureSampler" uniform
    TextureID  = glGetUniformLocation(program, "myTextureSampler");
    
    perspectiveMatrixID = glGetUniformLocation(program, "mP");
    viewMatrixID = glGetUniformLocation(program, "mV");
    modelMatrixID = glGetUniformLocation(program, "mM");
    room->setTexture("img.bmp");
    sphere->setTexture("uvmap.DDS");
    glClearColor(0.9, 0.9, 0.9, 1.0);
//    singleton->playMusic();
}

void Game::reset()
{
//    singleton->playMusic();
    eyeX = 1;
    eyeY = 1;
    eyeZ = 3;
    centerX = 1;
    centerY = 1;
    centerZ = -1000;
    singleton->score = 0;
//    ap->
//    singleton->playMusic();
    //singleton->room->reset();
}

void print(int x, int y, int z, char *string)
{
    int len, i;
    glRasterPos3f(x, y, z);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
    }
}


void Game::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    singleton->room->writeBuffer();
    singleton->sphere->writeBuffer();
    if (jump) singleton->sphere->jump();
    if (start) {
        singleton->eyeZ--;
        if (singleton->eyeZ < -290) {
            start = false;
            singleton->reset();
        }
        singleton->room->coll_ded();
//        PrintC(singleton->score);
        //    glPushMatrix();
        //    GLuint eboxTexture = LoadTexture("Earth.ppm", 720, 360, false);
        //    glTranslated(ballX, ballY, ballZ);
        //    GLUquadricObj* esphere = gluNewQuadric();
        //    gluQuadricTexture(esphere, true);
        //    gluQuadricNormals(esphere, GLU_SMOOTH);
        //    glEnable(GL_TEXTURE_2D);
        //    glBindTexture(GL_TEXTURE_2D, eboxTexture);
        //    glEnable(GL_CULL_FACE);
        //    gluSphere(esphere,0.6,100,100);
        //    gluDeleteQuadric(esphere);
        //    
        //    glPopMatrix();
        //    
        //    glDisable(GL_TEXTURE_2D);
        
        char text[100];
        sprintf(text, "Your Score is:%ld", singleton->score);
        print(4, 1, text);
    }
//    PrintC(singleton->eyeZ);
//    PrintC(singleton->eyeY);
//    PrintC(singleton->eyeX);
    glutSwapBuffers();
}

void Game::keyboard(unsigned char key, int x, int y)
{
    switch (key){
        case GLUT_KEY_LEFT:
            singleton->sphere->transLeft(1);
            break;
        case GLUT_KEY_RIGHT:
            singleton->sphere->transRight(1);
            break;
        case GLUT_KEY_UP:
            singleton->eyeZ--;
            break;
        case 'j':
            jump = true;
            break;
        case 's':
            start = true;
            break;
        case 'r':
            singleton->reset();
            break;
    }
}

void Game::mouse(int key, int x, int y, int z)
{

        jump = true;

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

void Game::setJump(bool status)
{
    jump = status;
}

void Game::game_over()
{
    is_game_over = true;
}