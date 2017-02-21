#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <texturemanager.h>

class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player();
    sf::RectangleShape & getDrawable();
private:
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    sf::RectangleShape sprite;
};

#endif // PLAYER_H
