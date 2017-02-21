#include "texturemanager.h"

TextureManager::TextureManager()
{
    loadLevel("basicTextures");
}

void TextureManager::loadLevel(const std::string & levelName)
{
    std::ifstream fin("Textures/"+levelName+"/"+levelName+".inf");
    std::string tName;
    while(fin>>tName)
    {
        if(!textures[tName].loadFromFile("Textures/"+levelName+"/"+tName+".png"))
        {
            std::cout<<"Failed to load "<<tName<<".png!\n";
        }
        else
        {
            std::cout<<"Loaded "<<tName<<".png!\n";
        }
    }
    fin.close();
}

sf::Texture *TextureManager::getTexture(const std::string & textureName)
{
    return &textures[textureName];
}

void TextureManager::unloadLevel(const std::string & levelName)
{
    std::ifstream fin("Textures/"+levelName+"/"+levelName+".inf");
    std::string tName;
    while(getline(fin, tName))
    {
        textures.erase(tName);
    }
    fin.close();
}
