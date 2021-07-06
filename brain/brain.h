//
// Created by buyolitsez on 7/6/21.
//

#pragma once

#include <iostream>
#include <fstream>
#include "../Constants.h"

class Ceil{
public:
    int left = 0, right = 0, up = 0, down = 0;
};

Ceil tableFruits[BRAIN_SEE][BRAIN_SEE];
Ceil tableBlock[BRAIN_SEE][BRAIN_SEE];

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