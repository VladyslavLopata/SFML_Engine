#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <SFML/Graphics.hpp>

#include <vector>


class Collisions
{

public:

    //setup the collisions for the level
    void resetCollisions(int *levelMap, int &lWidth, int &lHeigt, int &tWidth, int &tHeight);

    //check whether an rect hits the collider
    bool isWall(const sf::FloatRect & moveDir);

private:

    //map for the collisions
    std::vector<int> collisionMap;

    //width and height for level and tile
    int lWidth, lHeight, tWidth, tHeight;

};

#endif // COLLISIONS_H
