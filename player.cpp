#include "player.h"

Player::Player()
{
    sprite.setSize(sf::Vector2f(64,128));
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(sprite, states);
}

sf::RectangleShape & Player::getDrawable()
{
    return sprite;
}

void Player::handleInput(const float & delta)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        anim.setAnimRow(0);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        move(sf::Vector2f(-0.1,0.0));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        anim.setAnimRow(1);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        move(sf::Vector2f(0.1,0.0));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        anim.setAnimRow(2);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        move(sf::Vector2f(0.0,-0.1));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        anim.setAnimRow(3);
        anim.update(delta);
        sprite.setTextureRect(anim.getRect());
        move(sf::Vector2f(0.0,0.1));
    }
}

void Player::init(const sf::Vector2u &tSize)
{
    anim.reset(tSize, sf::Vector2f(4,4), 0.3);
}
