#ifndef COLLISIONS_H
#define COLLISIONS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class Collisions
{
public:
    Collisions();
    ~Collisions();
    void resetCollisions(int *levelMap, int &lWidth, int &lHeigt, int &tWidth, int &tHeight);
    bool isWall(const sf::FloatRect & moveDir);
private:
    std::vector<int> collisionMap;
    int lWidth, lHeight, tWidth, tHeight;
};

#endif // COLLISIONS_H
