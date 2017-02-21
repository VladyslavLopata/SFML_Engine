#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

class TextureManager
{
public:
    TextureManager();
    void loadLevel(const std::string & levelName);
    void unloadLevel(const std::string & levelName);
    sf::Texture * getTexture(const std::string & textureName);
private:
    std::map<std::string, sf::Texture> textures;
};

#endif // TEXTUREMANAGER_H
