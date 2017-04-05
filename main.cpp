#include <SFML/Graphics.hpp>
#include "world.h"
#include "systems.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture meme;
    if(!meme.loadFromFile("res/ykRkzxk.jpg"))
        return -1;

    sf::Sprite sprite(meme);

    World world;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        movement(&world);

        window.clear();
        window.draw(sprite);
        window.display();
    }
//
    return 0;
}