#include "engine.h"

Engine::Engine() :
    window{sf::VideoMode{800, 600, 32}, "GameWindow"}
{
    timer.restart();
}

void Engine::start()
{
    level.initialize();
    window.setFramerateLimit(60);
    loop();
}

void Engine::loop()
{

    while (window.isOpen())
    {
        update();
        draw();
    }

}

void Engine::update()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }

    level.updateInfo(timer.restart().asSeconds());

}

void Engine::draw()
{

    window.clear();
    window.draw(level);
    window.display();

}
