#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "animator.h"
#include "collisions.h"
#include <iostream>

class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player();
    void init();
    void handleInput(const float &delta, Collisions &col);
private:
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    sf::RectangleShape sprite;
    Animator anim;
    sf::Texture aMoving, aIdle;
};

#endif // PLAYER_H
