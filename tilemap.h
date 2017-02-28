#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

#include <string>

class TileMap : public sf::Drawable, public sf::Transformable
{

public:

    //load tilemap from the specified location
    bool load(const std::string & tileset, sf::Vector2u tileSize, int *tiles, unsigned int width, unsigned int height);

private:

    //drawing staff to the screen
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    //The map itself
    sf::VertexArray m_vertices;

    //tileset
    sf::Texture m_tileset;

};

#endif // TILEMAP_H
