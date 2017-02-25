#include "engine.h"

Engine::Engine() :
    window{sf::VideoMode{800, 600, 32}, "GameWindow"}
{
    timer.restart();
}

void Engine::start()
{
    player.init();
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
    float delta = timer.restart().asSeconds();
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }

    player.handleInput(delta);

}

void Engine::draw()
{

    window.clear();
    window.draw(level);
    window.draw(player);
    window.display();

}
