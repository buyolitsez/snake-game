//
// Created by buyolitsez on 7/3/21.
//

#ifndef SNAKE_GAME_SNAKEHEAD_H
#define SNAKE_GAME_SNAKEHEAD_H

#include "partOfSnake.h"

class snakeHead : public partOfSnake {
public:
    snakeHead(int x, int y) : partOfSnake(x, y, "head_square.png") {}
};


#endif //SNAKE_GAME_SNAKEHEAD_H
