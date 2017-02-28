#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>

#include <fstream>
#include <string>
#include <vector>

#include "collisions.h"
#include "tilemap.h"
#include "player.h"

class Level : public sf::Drawable, sf::Transformable
{

public:

    //initialize level on start
    void initialize();

    //updates info for the level
    void updateInfo(const float & delta);

private:

    //draw all the staff to the screen
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

    //read the .tmx file for the current level and setup all the objects
    void parseLevelInfo(std::string levelName);

    //class for the player
    Player player;

    //level info
    std::string curLevel;
    std::vector<TileMap> mapLayers;
    sf::Texture m_texture;

    //class for collision detection
    Collisions collisions;

    //level camera
    sf::View camera;

    //var for the current layer
    unsigned playerLayer;
};


#endif // LEVEL_H
