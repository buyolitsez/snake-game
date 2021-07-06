//
// Created by buyolitsez on 7/6/21.
//

#pragma once

#include <iostream>
#include <fstream>
#include "../Constants.h"
#include "../snakeFiles/Snake.h"
#include "../Map.h"

class Snake;

class Ceil{
public:
    int left = 0, right = 0, up = 0, down = 0;
    void add(int& left, int& right, int& up, int& down);
};

extern Ceil tableFruits[BRAIN_SEE][BRAIN_SEE];
extern Ceil tableBlock[BRAIN_SEE][BRAIN_SEE];

void loadTables();

void setTables();

int getDirection(Snake& snake);

