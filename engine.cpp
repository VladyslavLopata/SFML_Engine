#include "engine.h"

Engine::Engine() :
    window{sf::VideoMode{800, 600, 32}, "GameWindow"},
    tManager(new TextureManager())
{
    player.getDrawable().setTexture(tManager->getTexture("Player"));
}

void Engine::start()
{
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

}

void Engine::draw()
{

    window.clear();
    window.draw(player);
    window.display();

}
