#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Fruit.h"
#include <string>
#include "Snake.h"

void changeDirSnake(Snake& snake);


int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDOW_WIDTH, WIDOW_HEIGHT), "snake game");

    sf::Font font;
    font.loadFromFile("../fonts/BebasNeue-Regular.ttf");
    sf::Text text("", font, 40);
    text.setColor(sf::Color::Blue);


    sf::Clock clock;

    Snake snake = Snake();

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
        if (snake.alive) {
            window.clear();

            drawMap(window);

            mainFruit.draw(window);

            changeDirSnake(snake);
            snake.update(nowTime);
            snake.draw(window);

            text.setString("Fruits: " + std::to_string(snake.countOfFruits));
            window.draw(text);

            window.display();

        }
    }
    return 0;
}


void changeDirSnake(Snake& snake) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        snake.changeDirHead(1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        snake.changeDirHead(2);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        snake.changeDirHead(3);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        snake.changeDirHead(4);
    }
}