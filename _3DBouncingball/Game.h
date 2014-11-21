//
//  Game.h
//  _3DBouncingball
//
//  Created by Ahmed Mohamed Fareed on 11/15/14.
//  Copyright (c) 2014 Ahmed Mohamed Fareed. All rights reserved.
//

#ifndef ___3DBouncingball__Game__
#define ___3DBouncingball__Game__

#include "Constants.h"
#include "Room.h"
#include "Ball.h"
#include "Cube.h"

class Cube;

class Game {

private:
    bool is_game_over;
    Ball ball;
    Room room;
    Cube* cube;
    
protected:
    void init();
    void reset();
    static void display();
    static void keyboard(unsigned char key, int x, int y);
    static void special(int key, int x, int y);
    static void idle();
    void output(int x, int y, char *string);
    void initMatrices();
    void setColorArray(GLuint id);
    
public:
    static Game *singleton;
    void game_over();
    void run(int argc, char **argv);
    GLuint getProgramID();
};

#endif /* defined(___3DBouncingball__Game__) */
