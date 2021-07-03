
#include "partOfSnake.h"

std::vector<partOfSnake*> snakeParts;

partOfSnake::partOfSnake(int X, int Y, sf::String FileName) {
    file = FileName;
    image.loadFromFile("../images/" + file);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    x = X; y = Y;
    sprite.setPosition(x * SIZEONESQUARE, y * SIZEONESQUARE);
    snakeParts.emplace_back(this);
}

void partOfSnake::Update(float time) {
    x += dx;
    y += dy;
    sprite.setPosition(x * SIZEONESQUARE, y * SIZEONESQUARE);
}

void partOfSnake::Draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}


void DrawSnake(sf::RenderWindow& window) {
    for (auto part : snakeParts) {
        part->Draw(window);
    }
}
