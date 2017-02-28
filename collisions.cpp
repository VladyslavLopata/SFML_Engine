#include "collisions.h"

void Collisions::resetCollisions(int *levelMap,int &lWidth, int &lHeight, int &tWidth, int &tHeight)
{

    //reset the map with provided values
    collisionMap.clear();
    collisionMap.resize(lWidth * lHeight);

    for(int i = 0; i < lWidth * lHeight; i++)
    {
        collisionMap[i] = levelMap[i];
    }

    this->lHeight = lHeight;
    this->lWidth = lWidth;
    this->tWidth = tWidth;
    this->tHeight = tHeight;
}

bool Collisions::isWall(const sf::FloatRect &moveDir)
{

    //change collider dimensions
    sf::FloatRect plBot(moveDir.left + moveDir.width/3.0, moveDir.top, moveDir.width/3.0, moveDir.height);

    //if collider goes off the map return collision
    if(plBot.top/tHeight <= 0 || (plBot.top + plBot.height)/tHeight > lHeight
            || plBot.left/tWidth <= 0 || (plBot.left + plBot.width)/tWidth > lWidth)
    {
        return true;
    }

    //calculate rect vertices
    int top = plBot.top/tHeight;
    int left = plBot.left/tWidth;
    int right = (plBot.left + plBot.width)/tWidth;
    int bot = (plBot.top + plBot.height)/tHeight;

    //return the collision if at least one of the vertices is colliding
    return collisionMap[left + top * lWidth] || collisionMap[left + bot*lWidth]
            ||collisionMap[right + top * lWidth] || collisionMap[right + bot*lWidth];

}
