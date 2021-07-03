
#include "partOfSnake.h"

std::vector<partOfSnake*> snakeParts;


partOfSnake::partOfSnake(int X, int Y, sf::String FileName) {
    file = FileName;
    image.loadFromFile("../images/" + file + "_up.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    x = X; y = Y;
    time = 0;
    dir = Up;
    sprite.setPosition(x * SIZEONESQUARE, y * SIZEONESQUARE);
    snakeParts.emplace_back(this);
}

void partOfSnake::Update(float t) {
    time += t;
    if (time >= TimeToUpdate) {
        x += dx;
        y += dy;
        if (x == WIDTH) {
            x = 0;
        }
        if (y == HEIGHT) {
            y = 0;
        }
        sprite.setPosition(x * SIZEONESQUARE, y * SIZEONESQUARE);
        time -= TimeToUpdate;
    }
}

void partOfSnake::CorrectRotation() {
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

void partOfSnake::Draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}


void DrawSnake(sf::RenderWindow& window) {
    for (auto part : snakeParts) {
        part->Draw(window);
    }
}

void UpdateSnake(float time) {
    for (auto part : snakeParts) {
        part->Update(time);
    }
}


void ChangeDirHead(Direction dir) {
    if (snakeParts[0]->dir == dir) {
        return;
    }
    snakeParts[0]->dir = dir;
    if (dir == Direction::Left) {
        snakeParts[0]->dx = -1;
        snakeParts[0]->dy = 0;
    } else if (dir == Direction::Right) {
        snakeParts[0]->dx = 1;
        snakeParts[0]->dy = 0;
    } else if (dir == Direction::Up) {
        snakeParts[0]->dx = 0;
        snakeParts[0]->dy = -1;
    } else {
        snakeParts[0]->dx = 0;
        snakeParts[0]->dy = 1;
    }
    snakeParts[0]->CorrectRotation();
}
