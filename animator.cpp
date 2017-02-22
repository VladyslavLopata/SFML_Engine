#include "animator.h"

void Animator::setAnimRow(const unsigned &row)
{
    animRect.top = row*dy;
}

const sf::IntRect & Animator::getRect()
{
    return animRect;
}

void Animator::reset(const sf::Vector2u &tSize, const sf::Vector2f &frameNum, const float &speed)
{
    this->speed = speed;
    dx = tSize.x/frameNum.x;
    dy = tSize.y/frameNum.y;
    fx = frameNum.x;
    fy = frameNum.y;
    animRect = sf::Rect<int>(0,0,dx,dy);
}

void Animator::update(const float &dt)
{
    curTime += dt;
    if(curTime >= speed)
    {
        curTime -= speed;
        animRect.left+=dx;
        if(animRect.left >= fx*dx)
        {
            animRect.left = 0;
        }
    }
}
