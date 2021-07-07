//
// Created by buyolitsez on 7/4/21.
//

#include "Fruit.h"

std::vector <Fruit> vectorFruits;
extern std::vector <Snake> vectorSnakes;

Fruit::Fruit() {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    rnd = std::mt19937(0);
    this->findPosition();
}

void Fruit::draw(sf::RenderWindow& window) {
    sf::Texture texture;
    texture.loadFromFile("../images/fruit_square.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(x * SIZE_ONE_SQUARE_OF_MAP, y * SIZE_ONE_SQUARE_OF_MAP);
    window.draw(sprite);
}

void Fruit::findPosition() {
    bool placeIsBusy;
    int countToTry = 100;
    do{
        placeIsBusy = false;
        x = rnd() % WIDTH_OF_MAP;
        y = rnd() % HEIGHT_OF_MAP;
        if (isFruit[x][y] || isBlock[x][y]) {
            placeIsBusy = true;
        }
    }while(placeIsBusy && countToTry--);
    isFruit[x][y]++;
}

void startFruits(int n) {
    for (int i = 0; i < n; ++i) {
        vectorFruits.emplace_back(Fruit());
    }
}

void drawFruits(sf::RenderWindow& window) {
    for (auto &fruit : vectorFruits) {
        fruit.draw(window);
    }
}

bool eatFruit(int x, int y) {
    for (int i = 0; i < vectorFruits.size(); ++i) {
        if (vectorFruits[i].x == x && vectorFruits[i].y == y) {
            isFruit[x][y]--;
            vectorFruits.erase(vectorFruits.begin() + i);
            vectorFruits.emplace_back(Fruit());
            return true;
        }
    }
    return false;
}