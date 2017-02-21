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
