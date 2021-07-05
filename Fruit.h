//
// Created by buyolitsez on 7/4/21.
//


#pragma once

#include <random>
#include <chrono>
#include <vector>
#include <SFML/Graphics.hpp>

class Fruit;

extern std::vector <Fruit> vectorFruits;

class Fruit {
public:
    std::mt19937 rnd;
    int x, y;
    Fruit();
    void findPosition();
    void draw(sf::RenderWindow& window);
};

void startFruits(int n);

void drawFruits(sf::RenderWindow& window);

bool eatFruit(int x, int y);
