//
// Created by buyolitsez on 7/6/21.
//

#pragma once

#include <iostream>
#include <fstream>
#include "../Constants.h"
#include "../snakeFiles/Snake.h"
#include "../Map.h"
#include <cassert>

class Snake;

class Ceil{
public:
    int left = 0, right = 0, up = 0, down = 0;
    void add(int& left, int& right, int& up, int& down);
    void correct(int dir, int val);
};

//extern Ceil tableFruits[BRAIN_SEE][BRAIN_SEE];
//extern Ceil tableBlock[BRAIN_SEE][BRAIN_SEE];

void setTablesDebug();

void loadTables();

void setTables();

int getDirection(Snake& snake);

void addTable(Snake& snake, int dir, int val);
