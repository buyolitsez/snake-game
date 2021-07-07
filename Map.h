#pragma once


#include <SFML/Graphics.hpp>
#include "Constants.h"


void drawMap(sf::RenderWindow& window);

extern int isFruit[WIDTH_OF_MAP][HEIGHT_OF_MAP];
extern int isBlock[WIDTH_OF_MAP][HEIGHT_OF_MAP];

bool inBounds(int x, int y);