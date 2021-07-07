//
// Created by buyolitsez on 7/5/21.
//

#include "Snake.h"

std::vector<Snake> vectorSnakes;

Snake::Snake() {
    snakeParts.emplace_back(PartOfSnake("head_square"));
}

bool Snake::checkDir(int dx, int dy) {
    return !(snakeParts.size() > 1 && snakeParts[0].x + dx == snakeParts[1].x && snakeParts[0].y + dy == snakeParts[1].y);
}

void Snake::changeDirHead(int dir) {
    if (snakeParts[0].dir == dir) {
        return;
    }
    bool changed = true;
    if (dir == 1 && checkDir(-1, 0)) {
        dx = -1;
        dy = 0;
    } else if (dir == 2 && checkDir(1, 0)) {
        dx = 1;
        dy = 0;
    } else if (dir == 3 && checkDir(0, -1)) {
        dx = 0;
        dy = -1;
    } else if (dir == 4 && checkDir(0, 1)) {
        dx = 0;
        dy = 1;
    } else {
        changed = false;
    }
    if (changed) {
        snakeParts[0].dir = dir;
        snakeParts[0].correctRotation();
    }
}

void Snake::update(float t) {
    time += t;
    if (time >= TIME_TO_UPDATE_FRAME) {
        if (dx == 0 && dy == 0) {return;}
        int nextX = snakeParts[0].x + dx;
        int nextY = snakeParts[0].y + dy;
        if (isBlock[nextX][nextY] || !inBounds(nextX, nextY)) {
            alive = false;
            return;
        }
        for (int i = int(snakeParts.size()) - 1; i > 0; --i) {
            --isBlock[snakeParts[i].x][snakeParts[i].y];
            snakeParts[i].x = snakeParts[i - 1].x;
            snakeParts[i].y = snakeParts[i - 1].y;
            ++isBlock[snakeParts[i].x][snakeParts[i].y];
            snakeParts[i].dir = snakeParts[i - 1].dir;
            snakeParts[i].correctRotation();
            snakeParts[i].sprite.setPosition(snakeParts[i].x * SIZE_ONE_SQUARE_OF_MAP, snakeParts[i].y * SIZE_ONE_SQUARE_OF_MAP);
        }
        --isBlock[snakeParts[0].x][snakeParts[0].y];
        snakeParts[0].x = nextX;
        snakeParts[0].y = nextY;
        ++isBlock[nextX][nextY];
        snakeParts[0].sprite.setPosition(snakeParts[0].x * SIZE_ONE_SQUARE_OF_MAP, snakeParts[0].y * SIZE_ONE_SQUARE_OF_MAP);
        time = 0;
        if (eatFruit(snakeParts[0].x, snakeParts[0].y)) {
            add();
        }
    }
}

void Snake::draw(sf::RenderWindow& window) {
    for (auto &part : snakeParts) {
        part.draw(window);
    }
}

void Snake::add() {
    countOfFruits++;
    snakeParts.emplace_back("tail_square");
    snakeParts[0].correctRotation();
}

int Snake::getX() {
    return snakeParts[0].x;
}

int Snake::getY() {
    return snakeParts[0].y;
}

void startSnakes(int n) {
    for (int i = 0; i < n; ++i) {
        vectorSnakes.emplace_back(Snake());
    }
}

bool isAliveSnakes() {
    for (auto &snake : vectorSnakes) {
        if (snake.alive) {
            return true;
        }
    }
    return false;
}

void changeDirHead(int i, sf::RenderWindow& window) {
    int dir = getDirection(vectorSnakes[i]);
    int user = cinDirection();
    if (dir != user) {
        addTable(vectorSnakes[i], user, 1);
        addTable(vectorSnakes[i], dir, -1);
    }
    vectorSnakes[i].changeDirHead(user);
}

void updateSnake(int i, float t) {
    vectorSnakes[i].update(t);
}

void drawSnakes(sf::RenderWindow& window) {
    for (auto &snake : vectorSnakes) {
        snake.draw(window);
    }
}

int getAmountOfFruits(int i) {
    return vectorSnakes[i].countOfFruits;
}

int cinDirection() {
    while(true) {
        bool pressed = false;
        while (!pressed) {
            pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) |
                      sf::Keyboard::isKeyPressed(sf::Keyboard::Right) |
                      sf::Keyboard::isKeyPressed(sf::Keyboard::Up) |
                      sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            return 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            return 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            return 3;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            return 4;
        }
    }
}