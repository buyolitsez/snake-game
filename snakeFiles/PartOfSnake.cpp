
#include "PartOfSnake.h"


PartOfSnake::PartOfSnake(sf::String FileName) {
    file = FileName;
    image.loadFromFile("../images/" + file + "_up.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(x * SIZE_ONE_SQUARE_OF_MAP, y * SIZE_ONE_SQUARE_OF_MAP);
}

void PartOfSnake::correctRotation(){
    sf::String add;
    switch(this->dir) {
        case 1: add = "_left"; break;
        case 2: add = "_right"; break;
        case 3: add = "_up"; break;
        case 4: add = "_down"; break;
    }
    this->image.loadFromFile("../images/" + this->file + add + ".png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

void PartOfSnake::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

