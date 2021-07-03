#pragma once


#include <SFML/Graphics.hpp>
#include "map.h"
#include <vector>

class partOfSnake {
public:
    float x, y, dx = 0, dy = 0;
    sf::String file;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    partOfSnake(int X, int Y, sf::String FileName);
    void Update(float time);
    void Draw(sf::RenderWindow& window);
};

void DrawSnake(sf::RenderWindow& window);
