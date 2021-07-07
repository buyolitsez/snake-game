//
// Created by buyolitsez on 7/6/21.
//

#include "brain.h"

Ceil tableFruits[BRAIN_SEE][BRAIN_SEE];
Ceil tableBlock[BRAIN_SEE][BRAIN_SEE];

int isFruit[WIDTH_OF_MAP][HEIGHT_OF_MAP];
int isBlock[WIDTH_OF_MAP][HEIGHT_OF_MAP];

void Ceil::add(int& left, int& right, int& up, int& down) {
    left += this->left;
    right += this->right;
    up += this->up;
    down += this->down;
}

void Ceil::correct(int dir, int val) {
    switch(dir) {
        case 1: left += val; break;
        case 2: right += val; break;
        case 3: up += val; break;
        case 4: down += val; break;
    }
}

void loadTables() {
    freopen("../brain/tables.txt", "r", stdin);
    for (int i = 0; i < BRAIN_SEE; ++i) {
        for (int j = 0; j < BRAIN_SEE; ++j) {
            std::cin >> tableFruits[i][j].left >> tableFruits[i][j].right >> tableFruits[i][j].up >> tableFruits[i][j].down;
        }
    }
    for (int i = 0; i < BRAIN_SEE; ++i) {
        for (int j = 0; j < BRAIN_SEE; ++j) {
            std::cin >> tableBlock[i][j].left >> tableBlock[i][j].right >> tableBlock[i][j].up >> tableBlock[i][j].down;
        }
    }
}

void setTables() {
    std::ofstream ofs;
    ofs.open("../brain/fakeTables.txt", std::ios::out | std::ios::trunc);
    for (int i = 0; i < BRAIN_SEE; ++i) {
        for (int j = 0; j < BRAIN_SEE; ++j) {
            ofs << tableFruits[i][j].left << " " << tableFruits[i][j].right << " " << tableFruits[i][j].up << " " << tableFruits[i][j].down << '\n';
        }
    }
    for (int i = 0; i < BRAIN_SEE; ++i) {
        for (int j = 0; j < BRAIN_SEE; ++j) {
            ofs << tableBlock[i][j].left << " " << tableBlock[i][j].right << " " << tableBlock[i][j].up << " " << tableBlock[i][j].down << '\n';
        }
    }
}

int getDirection(Snake& snake) {
    int half = BRAIN_SEE / 2;
    int left = 0, right = 0, up = 0, down = 0;
    for (int dx = -half; dx <= half; ++dx) {
        for (int dy = -half; dy <= half; ++dy) {
            int x = snake.getX() + dx;
            int y = snake.getY() + dy;
            if (!inBounds(x, y)) {continue;}
            if (!inBounds(x, y) || isBlock[x][y]) {
                tableBlock[dx + half][dy + half].add(left, right, up, down);
            } else if (isFruit[x][y]) {
                tableFruits[dx + half][dy + half].add(left, right, up, down);
            }
        }
    }
    if (left >= std::max({right, up, down})) {
        return 1;
    }
    if (right >= std::max({left, up, down})) {
        return 2;
    }
    if (up >= std::max({left, right, down})) {
        return 3;
    }
    if (down >= std::max({right, up, left})) {
        return 4;
    }
}

void addTable(Snake& snake, int dir, int val) {
    int half = BRAIN_SEE / 2;
    for (int dx = -half; dx <= half; ++dx) {
        for (int dy = -half; dy <= half; ++dy) {
            if (dx == 0 && dy == 0) {continue;}
            int x = snake.getX() + dx;
            int y = snake.getY() + dy;
            if (!inBounds(x, y) || isBlock[x][y]) {
                tableBlock[dx + half][dy + half].correct(dir, val);
            } else if (isFruit[x][y]) {
                tableFruits[dx + half][dy + half].correct(dir, val);
            }
        }
    }
}