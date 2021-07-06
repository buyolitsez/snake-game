#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Fruit.h"
#include <string>
#include "snakeFiles/Snake.h"
#include "brain/brain.h"

void changeDirSnake(int i);


int main()
{
    loadTables();
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
        float nowTime = clock.getElapsedTime().asMicroseconds();
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
    setTables();
    return 0;
}


void changeDirSnake(int i) {
    changeDirHead(i);
}