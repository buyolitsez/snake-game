
#include "map.h"

void DrawMap(sf::RenderWindow& window) {
    sf::Texture mapSquareTexture;
    mapSquareTexture.loadFromFile("../images/map_one_square.png");

    sf::Sprite mapSquareSprite;
    mapSquareSprite.setTexture(mapSquareTexture);
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            mapSquareSprite.setPosition(x * SIZEONESQUARE, y * SIZEONESQUARE);
            window.draw(mapSquareSprite);
        }
    }
}

