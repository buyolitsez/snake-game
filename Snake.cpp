//
// Created by buyolitsez on 7/5/21.
//

#include "Snake.h"

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
        for (int i = int(snakeParts.size()) - 1; i > 0; --i) {
            if (x + dx == snakeParts[i].x && y + dy == snakeParts[i].y) {
                alive = false;
            }
            snakeParts[i].x = snakeParts[i - 1].x;
            snakeParts[i].y = snakeParts[i - 1].y;
            snakeParts[i].dir = snakeParts[i - 1].dir;
            snakeParts[i].correctRotation();
            snakeParts[i].sprite.setPosition(snakeParts[i].x * SIZE_ONE_SQUARE_OF_MAP, snakeParts[i].y * SIZE_ONE_SQUARE_OF_MAP);
        }
        x = (x + dx + WIDTH_OF_MAP) % WIDTH_OF_MAP;
        y = (y + dy + HEIGHT_OF_MAP) % HEIGHT_OF_MAP;
        snakeParts[0].sprite.setPosition(x * SIZE_ONE_SQUARE_OF_MAP, y * SIZE_ONE_SQUARE_OF_MAP);
        time = 0;
    }
}

void Snake::draw(sf::RenderWindow& window) {
    for (auto &part : snakeParts) {
        part.draw(window);
    }
}