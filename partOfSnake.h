#pragma once

#include <SFML/Graphics.hpp>
#include "map.h"
#include <vector>

enum Direction {
    None,
    Left,
    Right,
    Up,
    Down
};


class partOfSnake {
public:
    int x, y, dx = 0, dy = 0;
    sf::String file;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    Direction dir;
    float time = 0;
    partOfSnake(int X, int Y, sf::String FileName);
    void Update(float time);
    void Draw(sf::RenderWindow& window);
    void CorrectRotation();
};

void DrawSnake(sf::RenderWindow& window);

extern std::vector<partOfSnake*> snakeParts;

void UpdateSnake(float time);

void ChangeDirHead(Direction dir);
