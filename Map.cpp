
#include "Map.h"

void drawMap(sf::RenderWindow& window) {
    sf::Texture mapSquareTexture;
    mapSquareTexture.loadFromFile("../images/map_one_square.png");

    sf::Sprite mapSquareSprite;
    mapSquareSprite.setTexture(mapSquareTexture);
    for (int x = 0; x < WIDTH_OF_MAP; ++x) {
        for (int y = 0; y < HEIGHT_OF_MAP; ++y) {
            mapSquareSprite.setPosition(x * SIZE_ONE_SQUARE_OF_MAP, y * SIZE_ONE_SQUARE_OF_MAP);
            window.draw(mapSquareSprite);
        }
    }
}

bool inBounds(int x, int y) {
    return x >= 0 && y >= 0 && x < WIDTH_OF_MAP && y < HEIGHT_OF_MAP;
}

