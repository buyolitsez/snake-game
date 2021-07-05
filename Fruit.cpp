//
// Created by buyolitsez on 7/4/21.
//

#include "Fruit.h"

extern std::vector<PartOfSnake> snakeParts;
extern int countOfFruits = 0;


Fruit::Fruit() {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    rnd = std::mt19937(seed);
    this->findPosition();
}

void Fruit::draw(sf::RenderWindow& window) {
    if (x == snakeParts[0].x && y == snakeParts[0].y) {
        ++countOfFruits;
        PartOfSnake newPart = PartOfSnake(snakeParts[0].x, snakeParts[0].y, "tail_square");
        this->findPosition();
    }
    sf::Texture texture;
    texture.loadFromFile("../images/fruit_square.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(x * SIZE_ONE_SQUARE_OF_MAP, y * SIZE_ONE_SQUARE_OF_MAP);
    window.draw(sprite);
}

void Fruit::findPosition() {
    bool placeIsBusy;
    do{
        placeIsBusy = false;
        x = rnd() % WIDTH_OF_MAP;
        y = rnd() % HEIGHT_OF_MAP;
        for (auto& part : snakeParts) {
            if (part.x == x && part.y == y) {
                placeIsBusy = true;
                break;
            }
        }
    }while(placeIsBusy);
}