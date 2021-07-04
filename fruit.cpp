//
// Created by buyolitsez on 7/4/21.
//

#include "fruit.h"

extern std::vector<partOfSnake> snakeParts;

fruit::fruit() {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    rnd = std::mt19937(seed);
    this->FindPosition();
}

void fruit::Draw(sf::RenderWindow& window) {
    if (x == snakeParts[0].x && y == snakeParts[0].y) {
        partOfSnake newPart = partOfSnake(snakeParts[0].x, snakeParts[0].y, "tail_square");
        this->FindPosition();
    }
    sf::Texture texture;
    texture.loadFromFile("../images/fruit_square.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(x * SIZEONESQUARE, y * SIZEONESQUARE);
    window.draw(sprite);
}

void fruit::FindPosition() {
    bool placeIsBusy;
    do{
        placeIsBusy = false;
        x = rnd() % WIDTH;
        y = rnd() % HEIGHT;
        for (auto& part : snakeParts) {
            if (part.x == x && part.y == y) {
                placeIsBusy = true;
                break;
            }
        }
    }while(placeIsBusy);
}