
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
        if (dx == 0 && dy == 0) {return;}
        for (int i = int(snakeParts.size()) - 1; i > 0; --i) {
            snakeParts[i]->x = snakeParts[i - 1]->x;
            snakeParts[i]->y = snakeParts[i - 1]->y;
            snakeParts[i]->dir = snakeParts[i - 1]->dir;
            snakeParts[i]->CorrectRotation();
            snakeParts[i]->sprite.setPosition(snakeParts[i]->x * SIZEONESQUARE, snakeParts[i]->y * SIZEONESQUARE);
        }
        x = (x + dx + WIDTH) % WIDTH;
        y = (y + dy + HEIGHT) % HEIGHT;
        sprite.setPosition(x * SIZEONESQUARE, y * SIZEONESQUARE);
        time = 0;
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
    snakeParts[0]->Update(time);
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
