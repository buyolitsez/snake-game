//
// Created by buyolitsez on 7/3/21.
//

#ifndef SNAKE_GAME_PARTOFSNAKE_H
#define SNAKE_GAME_PARTOFSNAKE_H

#include <SFML/Graphics.hpp>
#include "map.h"
#include "snake.h"


class partOfSnake {
public:
    float x, y, dx = 0, dy = 0;
    sf::String file;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    partOfSnake(int X = 0, int Y = 0, sf::String FileName = "");
    void Update(float time);
    void Draw(sf::RenderWindow& window);
};


#endif //SNAKE_GAME_PARTOFSNAKE_H
