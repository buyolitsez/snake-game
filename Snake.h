//
// Created by buyolitsez on 7/5/21.
//


#pragma once

#include "PartOfSnake.h"
#include "Fruit.h"


class PartOfSnake;
class Snake;

extern std::vector <Snake> vectorSnakes;

class Snake {
public:
    bool alive = true;
    int countOfFruits = 0;
    float time = 0;
    int dx = 0, dy = 0;
    std::vector<PartOfSnake> snakeParts;
    Snake();
    void changeDirHead(int dir);
    void update(float t);
    void draw(sf::RenderWindow& window);
    bool checkDir(int dx, int dy);
    void add();
};

void startSnakes(int n);

bool isAliveSnakes();

void changeDirHead(int i, int dir);

void updateSnake(int i, float t);

void drawSnakes(sf::RenderWindow& window);

int getAmountOfFruits(int i);
