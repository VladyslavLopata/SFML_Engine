#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "animator.h"

class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player();
    sf::RectangleShape & getDrawable();
    Animator anim;
private:
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    sf::RectangleShape sprite;
};

#endif // PLAYER_H
