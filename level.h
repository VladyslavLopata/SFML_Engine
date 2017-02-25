#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "tilemap.h"

class Level : public sf::Drawable, sf::Transformable
{
public:
    Level();
    ~Level();
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
private:
    void parseLevelInfo(std::string levelName);
    std::string curLevel;
    std::vector<TileMap> mapLayers;
    sf::Texture m_texture;
};


#endif // LEVEL_H
