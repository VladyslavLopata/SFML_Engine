#include "engine.h"

Engine::Engine() :
    window{sf::VideoMode{800, 600, 32}, "GameWindow"},
    tManager(new TextureManager())
{
    player.getDrawable().setTexture(tManager->getTexture("Player"));
    player.anim.reset(*tManager->getTexture("Player"), sf::Vector2f(4, 4), 0.3f);
    timer.restart();
    player.getDrawable().setTextureRect(sf::IntRect(0,0,16,16));
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
    float delta = timer.restart().asSeconds();
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.anim.setAnimRow(0);
        player.anim.update(delta);
        player.getDrawable().setTextureRect(player.anim.getRect());
        player.move(sf::Vector2f(-0.1,0.0));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.anim.setAnimRow(1);
        player.anim.update(delta);
        player.getDrawable().setTextureRect(player.anim.getRect());
        player.move(sf::Vector2f(0.1,0.0));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.anim.setAnimRow(2);
        player.anim.update(delta);
        player.getDrawable().setTextureRect(player.anim.getRect());
        player.move(sf::Vector2f(0.0,-0.1));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.anim.setAnimRow(3);
        player.anim.update(delta);
        player.getDrawable().setTextureRect(player.anim.getRect());
        player.move(sf::Vector2f(0.0,0.1));
    }


}

void Engine::draw()
{

    window.clear();
    window.draw(player);
    window.display();

}
