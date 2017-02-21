#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <SFML/Graphics.hpp>

class Animator
{
public:
    const sf::IntRect &getRect();
    void update(const float & dt);
    void setAnimRow(const unsigned & row);
    void reset(sf::Texture & texture, const sf::Vector2f & frameNum, const float & speed);
private:
    sf::IntRect animRect;
    float curTime, speed;
    float dx, dy, fx, fy;
};

#endif // ANIMATION_H
