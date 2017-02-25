#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <SFML/Graphics.hpp>

class Animator
{
public:
    const sf::IntRect &getRect();
    void update(const float & dt);
    void setAnimRow(const unsigned & row);
    void reset(const sf::Vector2u & tSize, const sf::Vector2f & frameNum, const float & speed);
    void hold(float delta);
private:
    sf::IntRect animRect;
    float curTime, speed;
    float dx, dy, fx, fy;
};

#endif // ANIMATION_H
