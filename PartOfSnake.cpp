
#include "PartOfSnake.h"

std::vector<PartOfSnake> snakeParts;


PartOfSnake::PartOfSnake(int X, int Y, sf::String FileName) {
    file = FileName;
    image.loadFromFile("../images/" + file + "_up.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    x = X; y = Y;
    time = 0;
    dir = Up;
    sprite.setPosition(x * SIZE_ONE_SQUARE_OF_MAP, y * SIZE_ONE_SQUARE_OF_MAP);
    snakeParts.emplace_back(*this);
}

void PartOfSnake::update(float t) {
    time += t;
    if (time >= TIME_TO_UPDATE_FRAME) {
        if (dx == 0 && dy == 0) {return;}
        for (int i = int(snakeParts.size()) - 1; i > 0; --i) {
            snakeParts[i].x = snakeParts[i - 1].x;
            snakeParts[i].y = snakeParts[i - 1].y;
            snakeParts[i].dir = snakeParts[i - 1].dir;
            snakeParts[i].correctRotation();
            snakeParts[i].sprite.setPosition(snakeParts[i].x * SIZE_ONE_SQUARE_OF_MAP, snakeParts[i].y * SIZE_ONE_SQUARE_OF_MAP);
        }
        x = (x + dx + WIDTH_OF_MAP) % WIDTH_OF_MAP;
        y = (y + dy + HEIGHT_OF_MAP) % HEIGHT_OF_MAP;
        sprite.setPosition(x * SIZE_ONE_SQUARE_OF_MAP, y * SIZE_ONE_SQUARE_OF_MAP);
        time = 0;
    }
}

void PartOfSnake::correctRotation() {
    sf::String add;
    switch(this->dir) {
        case Direction::Left: add = "_left"; break;
        case Direction::Right: add = "_right"; break;
        case Direction::Up: add = "_up"; break;
        case Direction::Down: add = "_down"; break;
    }
    this->image.loadFromFile("../images/" + this->file + add + ".png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

void PartOfSnake::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}


void drawSnake(sf::RenderWindow& window) {
    for (auto &part : snakeParts) {
        part.draw(window);
    }
}

void updateSnake(float time) {
    snakeParts[0].update(time);
}


void changeDirHead(Direction dir) {
    if (snakeParts[0].dir == dir) {
        return;
    }
    snakeParts[0].dir = dir;
    if (dir == Direction::Left) {
        snakeParts[0].dx = -1;
        snakeParts[0].dy = 0;
    } else if (dir == Direction::Right) {
        snakeParts[0].dx = 1;
        snakeParts[0].dy = 0;
    } else if (dir == Direction::Up) {
        snakeParts[0].dx = 0;
        snakeParts[0].dy = -1;
    } else {
        snakeParts[0].dx = 0;
        snakeParts[0].dy = 1;
    }
    snakeParts[0].correctRotation();
}
