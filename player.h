#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "collisions.h"
#include "animator.h"

class Player : public sf::Drawable, public sf::Transformable
{

public:

    //initialize player info on start
    void init();

    //handle input on update
    void handleInput(const float &delta, Collisions &col);

private:

    //draw all the staff to the screen
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

    //Rect for player
    sf::RectangleShape sprite;

    //animations class
    Animator anim;

    //textures for the animations
    sf::Texture aMoving, aIdle;

};

#endif // PLAYER_H
