#include <SFML/Graphics.hpp>
#include "map.h"
#include "partOfSnake.h"

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
    partOfSnake tail1(0, 1, "tail_square");
    partOfSnake tail2(0, 2, "tail_square");
    partOfSnake tail3(0, 3, "tail_square");
    partOfSnake tail4(0, 4, "tail_square");

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
        UpdateSnake(nowTime);
        DrawSnake(window);
        window.display();
    }
    return 0;
}