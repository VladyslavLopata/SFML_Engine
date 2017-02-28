#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <SFML/Graphics.hpp>

class Animator
{
public:

    //Rect that'll define the TextureRect for current frame
    const sf::IntRect &getRect();

    //function that updates animation info depending on the elapsed time
    void update(const float & dt);

    //if animation sheet has more than one row select the current row
    void setAnimRow(const unsigned & row);

    //change current settings for the animator
    void reset(const sf::Vector2u & tSize, const sf::Vector2f & frameNum, const float & speed);

    //freeze the animation
    void hold();

private:

    //rect that 'll be returned
    sf::IntRect animRect;

    //vars for elapsed time and frame change speed
    float curTime, speed;

    //size of frame and count for each axis
    float dx, dy, fx, fy;

};

#endif // ANIMATION_H
