#include <SFML/Graphics.hpp>
#include "Map.h"
#include "PartOfSnake.h"
#include "Fruit.h"

void changeDir() {
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

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "snake game");

    sf::Clock clock;

    PartOfSnake head(0, 0, "head_square");

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
        changeDir();
        window.clear();
        drawMap(window);

        mainFruit.draw(window);

        updateSnake(nowTime);
        drawSnake(window);
        window.display();
    }
    return 0;
}