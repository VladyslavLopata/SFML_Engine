#include "engine.h"

void Engine::start()
{

    const int FRAMERATE = 60;

    //initialize game objects
    window.create(sf::VideoMode(800,600,32), "Game Engine");
    timer.restart();
    window.setFramerateLimit(FRAMERATE);
    level.initialize();

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
