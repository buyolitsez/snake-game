//
// Created by buyolitsez on 7/3/21.
//

#include "partOfSnake.h"

partOfSnake::partOfSnake(int X, int Y, sf::String FileName) {
    file = FileName;
    image.loadFromFile("../images/" + file);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    x = X; y = Y;
//    snakeParts.emplace_back(*this);
}

void partOfSnake::Update(float time) {
    x += dx;
    y += dy;
    sprite.setPosition(x * SIZEONESQUARE, y * SIZEONESQUARE);
}

void partOfSnake::Draw(sf::RenderWindow& window) {

}
