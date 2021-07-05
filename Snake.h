//
// Created by buyolitsez on 7/5/21.
//


#pragma once

#include "PartOfSnake.h"


class PartOfSnake;

class Snake {
public:
    bool alive = true;
    int countOfFruits = 0;
    float time = 0;
    int dx = 0, dy = 0;
    int x = 0, y = 0;
    std::vector<PartOfSnake> snakeParts;
    Snake();
    void changeDirHead(int dir);
    void update(float t);
    void draw(sf::RenderWindow& window);
    bool checkDir(int dx, int dy);
};
