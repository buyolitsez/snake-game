//
// Created by buyolitsez on 7/4/21.
//


#pragma once

#include <random>
#include <chrono>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "snakeFiles/Snake.h"


class Fruit;

extern std::vector <Fruit> vectorFruits;

class Fruit {
    std::mt19937 rnd;
public:
    int x, y;
    Fruit();
    void findPosition();
    void draw(sf::RenderWindow& window);
};

void startFruits(int n);

void drawFruits(sf::RenderWindow& window);

bool eatFruit(int x, int y);
