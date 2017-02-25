#include "player.h"

Player::Player()
{
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(sprite, states);
}

void Player::handleInput(const float & delta)
{
    sprite.setTexture(&aMoving);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        anim.setAnimRow(1);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        move(sf::Vector2f(-0.1,0.0));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        anim.setAnimRow(2);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        move(sf::Vector2f(0.1,0.0));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        anim.setAnimRow(3);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        move(sf::Vector2f(0.0,-0.1));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        anim.setAnimRow(0);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        move(sf::Vector2f(0.0,0.1));
    }
    else
    {
        sprite.setTexture(&aIdle);
        anim.hold(delta);
        sprite.setTextureRect(anim.getRect());
    }
}

void Player::init()
{
    aIdle.loadFromFile("Levels/basicTextures/PlayerIdle.png");
    aMoving.loadFromFile("Levels/basicTextures/Player.png");
    sprite.setTexture(&aIdle);
    sprite.setSize(sf::Vector2f(aIdle.getSize().x/4, aIdle.getSize().y/4));
    sprite.setTextureRect(sf::IntRect(0,0,aIdle.getSize().x/4, aIdle.getSize().y/4));
    anim.reset(aIdle.getSize(), sf::Vector2f(4,4), 0.2);

}
