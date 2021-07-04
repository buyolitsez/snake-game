//
// Created by buyolitsez on 7/4/21.
//


#pragma once

#include "partOfSnake.h"
#include <random>
#include <chrono>

class fruit {
public:
    std::mt19937 rnd;
    int x, y;
    fruit();
    void FindPosition();
    void Draw(sf::RenderWindow& window);
};


