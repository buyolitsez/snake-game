#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include <vector>
#include "Constants.h"


enum Direction {
    None,
    Left,
    Right,
    Up,
    Down
};


class PartOfSnake {
public:
    int x, y, dx = 0, dy = 0;
    sf::String file;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    Direction dir;
    float time = 0;
    PartOfSnake(int X = 0, int Y = 0, sf::String FileName = "");
    void update(float time);
    void draw(sf::RenderWindow& window);
    void correctRotation();
};

void drawSnake(sf::RenderWindow& window);

extern std::vector<PartOfSnake> snakeParts;

void updateSnake(float time);

void changeDirHead(Direction dir);

Direction reverse(Direction dir);

bool checkDir(int dx, int dy);
