#include "animator.h"

void Animator::setAnimRow(const unsigned &row)
{

    //if the row isn't playing right now multiply row by size of the tile to get rect position
    if(animRect.top!= row*dy)
    {
        animRect.top = row*dy;
        curTime = 0;
    }
}

const sf::IntRect & Animator::getRect()
{
    return animRect;
}

void Animator::reset(const sf::Vector2u &tSize, const sf::Vector2f &frameNum, const float &speed)
{

    this->speed = speed;

    //calculate the dimensions of the frame
    dx = tSize.x/frameNum.x;
    dy = tSize.y/frameNum.y;

    //get number of frames
    fx = frameNum.x;
    fy = frameNum.y;

    //set the animation rect
    animRect = sf::IntRect(0,0,dx,dy);

}

void Animator::update(const float &dt)
{

    //elapse the time
    curTime += dt;

    //check whether switchtime is reached
    if(curTime >= speed)
    {
        //reset the elapsed time
        curTime -= speed;

        //change the rect
        animRect.left+=dx;
        if(animRect.left >= fx*dx)
        {
            animRect.left = 0;
        }

    }

}

void Animator::hold()
{

    //set all the vals to null
    animRect.left = 0;
    curTime = 0;

}
