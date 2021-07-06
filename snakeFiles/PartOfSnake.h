#pragma once

#include <SFML/Graphics.hpp>
#include "../Map.h"
#include <vector>
#include "../Constants.h"
#include "Snake.h"


class PartOfSnake {
public:
    int x = -1, y = -1;
    int dir = 3;
    sf::String file;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    PartOfSnake(sf::String FileName = "");
    void draw(sf::RenderWindow& window);
    void correctRotation();
};


