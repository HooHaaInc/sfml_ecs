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

    sf::Clock clock;
    sf::Time total = sf::milliseconds(0);
    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        sf::Time delta = elapsed - total;
        total = elapsed;

        // SFML event
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // call some system
        }

        //Game event
        GameEvent gameEvent;
        while (world.evlength > 0){
            gameEvent = unqueue_event(&world);
            //call some system
        }

        collision(&world, delta);
        movement(&world, delta);

        window.clear();
        draw(&world, &window, delta);
        window.display();
    }
//
    return 0;
}