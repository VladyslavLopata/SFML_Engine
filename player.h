#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "animator.h"

class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player();
    void init();
    void handleInput(const float &delta);
private:
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    sf::RectangleShape sprite;
    Animator anim;
    sf::Texture aMoving, aIdle;
};

#endif // PLAYER_H
