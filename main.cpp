#include <SFML/Graphics.hpp>
#include "map.h"
#include "partOfSnake.h"
#include "fruit.h"

void ChangeDir() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        ChangeDirHead(Direction::Left);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        ChangeDirHead(Direction::Right);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        ChangeDirHead(Direction::Up);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        ChangeDirHead(Direction::Down);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "snake game");

    sf::Clock clock;

    partOfSnake head(0, 0, "head_square");

    fruit mainFruit = fruit();

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
        ChangeDir();
        window.clear();
        DrawMap(window);

        mainFruit.Draw(window);

        UpdateSnake(nowTime);
        DrawSnake(window);
        window.display();
    }
    return 0;
}