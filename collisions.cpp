#include "collisions.h"

Collisions::Collisions()
{
}

Collisions::~Collisions()
{
}

void Collisions::resetCollisions(int *levelMap,int &lWidth, int &lHeight, int &tWidth, int &tHeight)
{
    collisionMap.clear();
    for(int i = 0; i < lWidth*lHeight; i++)
    {
        if(levelMap[i])
        {
            collisionMap.push_back(sf::FloatRect(i%lWidth*tWidth,i/lHeight*tHeight, tWidth, tHeight));
        }
    }
    this->lHeight = lHeight;
    this->lWidth = lWidth;
    this->tWidth = tWidth;
    this->tHeight = tHeight;
}

bool Collisions::isWall(const sf::FloatRect &moveDir)
{
    sf::FloatRect plBot(moveDir.left+moveDir.width/3, moveDir.top+moveDir.height/2, moveDir.width/3., moveDir.height/2);
    bool intersect = false;
    for(const auto & i : collisionMap)
    {
        if(i.intersects(plBot))
        {
            intersect = true;
            break;
        }
    }
    if(intersect)
    {
        return true;
    }
    return false;
}
