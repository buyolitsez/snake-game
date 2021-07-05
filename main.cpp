#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Fruit.h"
#include <string>
#include "Snake.h"

void changeDirSnake(int i);


int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDOW_WIDTH, WIDOW_HEIGHT), "snake game");

    sf::Font font;
    font.loadFromFile("../fonts/BebasNeue-Regular.ttf");
    sf::Text text("", font, 40);
    text.setColor(sf::Color::Blue);


    sf::Clock clock;

    startSnakes(1);

    startFruits(COUNT_OF_FRUITS);

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
        if (isAliveSnakes()) {
            window.clear();

            drawMap(window);

            drawFruits(window);

            changeDirSnake(0);
            updateSnake(0, nowTime);
            drawSnakes(window);

            text.setString("Fruits: " + std::to_string(getAmountOfFruits(0)));
            window.draw(text);

            window.display();

        }
    }
    return 0;
}


void changeDirSnake(int i) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        changeDirHead(i, 1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        changeDirHead(i, 2);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        changeDirHead(i, 3);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        changeDirHead(i, 4);
    }
}