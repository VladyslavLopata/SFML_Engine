#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "player.h"
#include "collisions.h"
#include "tilemap.h"

class Level : public sf::Drawable, sf::Transformable
{
public:
    void initialize();
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    void updateInfo(const float & delta);
private:
    void parseLevelInfo(std::string levelName);
    Player player;
    std::string curLevel;
    std::vector<TileMap> mapLayers;
    sf::Texture m_texture;
    Collisions collisions;
    sf::View camera;
    unsigned playerLayer;
};


#endif // LEVEL_H
