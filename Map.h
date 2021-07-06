#pragma once


#include <SFML/Graphics.hpp>
#include "Constants.h"


void drawMap(sf::RenderWindow& window);

extern bool isFruit[WIDTH_OF_MAP][HEIGHT_OF_MAP];
extern bool isBlock[WIDTH_OF_MAP][HEIGHT_OF_MAP];
