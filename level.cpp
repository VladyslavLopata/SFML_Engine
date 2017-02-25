#include "level.h"

Level::Level()

{
    m_texture.loadFromFile("Levels/basicTextures/tiles.png");
    parseLevelInfo("basicTextures");
}

Level::~Level()
{

}



void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    /*auto it = mapLayers.begin();
    while(it->isLoaded())
    {
        target.draw(*it,states);
        ++it;
    }*/
    for(const auto &i:mapLayers)
    {
        target.draw(i,states);
    }
}

void Level::parseLevelInfo(std::__cxx11::string levelName)
{
    int levelWidth, levelHeight, tileWidth, tileHeight;
    std::ifstream fin("Levels/"+levelName+"/map.tmx");
    std::string curLine;
    while(std::getline(fin, curLine))
    {
        if(curLine.find("<map")!=std::string::npos)
        {
            int pos = curLine.find("height=");
            levelHeight = std::stoi(curLine.substr(pos+8, curLine.find('\"',pos+8)-pos-8));

            pos = curLine.find("width=");
            levelWidth = std::stoi(curLine.substr(pos+7, curLine.find('\"',pos+7)-pos-7));

            pos = curLine.find("tilewidth=");
            tileWidth = std::stoi(curLine.substr(pos+11, curLine.find('\"',pos+11)-pos-11));

            pos = curLine.find("tileheight=");
            tileHeight = std::stoi(curLine.substr(pos+12, curLine.find('\"',pos+12)-pos-12));

        }
        else if (curLine.find("<layer")!=std::string::npos)
        {
            int pos = curLine.find("name=");
            std::string layerName = curLine.substr(pos+6, curLine.find('\"', pos+6)-pos-6);
            while (curLine.find('<')!=std::string::npos)
            {
                std::getline(fin, curLine);
            }
            std::vector<int> ln(levelWidth*levelHeight, 0);
            auto it = ln.begin();
            for(int i = 0; i < levelWidth; i++)
            {
                for(auto i = curLine.begin(); i != curLine.end(); i++)
                {
                    if(*i==',')
                    {
                        ++it;
                    }
                    else
                    {
                        *it = *it * 10 + *i-'0';
                    }
                }

                std::getline(fin, curLine);
            }
            TileMap cmap;
            cmap.load("Levels/"+levelName+"/tiles.png", sf::Vector2u(tileWidth, tileHeight),
                               ln,levelWidth, levelHeight);;
            mapLayers.push_back(cmap);

        }

    }
}
