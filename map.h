//
// Created by buyolitsez on 7/3/21.
//


#ifndef SNAKE_GAME_MAP_H
#define SNAKE_GAME_MAP_H

#include <SFML/Graphics.hpp>
#include "snake.h"

const int HEIGHT = 12;
const int WIDTH = 16;
const int SIZEONESQUARE = 64;

void DrawMap(sf::RenderWindow& window);

void DrawSnake(sf::RenderWindow& window);

#endif //SNAKE_GAME_MAP_H
