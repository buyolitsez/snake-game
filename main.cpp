#include <SFML/Graphics.hpp>
#include "map.h"
#include "partOfSnake.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "snake game");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        DrawMap(window);
        DrawSnake(window);
        window.display();
    }
    return 0;
}