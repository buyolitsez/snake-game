#include <SFML/Graphics.hpp>
#include "Map.h"
#include "PartOfSnake.h"
#include "Fruit.h"

void changeDirSnake() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        changeDirHead(Direction::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        changeDirHead(Direction::Right);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        changeDirHead(Direction::Up);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        changeDirHead(Direction::Down);
    }
}

bool snakeAlive;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDOW_WIDTH, WIDOW_HEIGHT), "snake game");

    sf::Font font;
    font.loadFromFile("../fonts/BebasNeue-Regular.ttf");
    sf::Text text("123abc", font, 40);


    sf::Clock clock;

    PartOfSnake head(0, 0, "head_square");
    snakeAlive = 1;

    Fruit mainFruit = Fruit();

    while (window.isOpen())
    {
        float nowTime = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (snakeAlive) {
            window.clear();

            drawMap(window);

            mainFruit.draw(window);

            changeDirSnake();
            updateSnake(nowTime);
            drawSnake(window);

            window.draw(text);

            window.display();

        }
    }
    return 0;
}