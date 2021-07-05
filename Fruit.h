//
// Created by buyolitsez on 7/4/21.
//


#pragma once

#include <random>
#include <chrono>
#include <vector>
#include <SFML/Graphics.hpp>

class Fruit;

class Fruit {
public:
    std::mt19937 rnd;
    int x, y;
    Fruit();
    void findPosition();
    void draw(sf::RenderWindow& window);
};


