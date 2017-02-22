#include "engine.h"

Engine::Engine() :
    window{sf::VideoMode{800, 600, 32}, "GameWindow"},
    tManager(new TextureManager())
{
    player.getDrawable().setTexture(tManager->getTexture("Player"));
    timer.restart();
    player.getDrawable().setTextureRect(sf::IntRect(0,0,16,16));
}

void Engine::start()
{
    player.init(tManager->getTexture("Player")->getSize());
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
    window.draw(player);
    window.display();

}
