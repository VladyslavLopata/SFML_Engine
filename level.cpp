#include "level.h"
void Level::initialize()
{
    m_texture.loadFromFile("Levels/basicTextures/tiles.png");
    parseLevelInfo("basicTextures");
    player.init();
    player.setPosition(32,1408);
}

void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.setView(camera);
    for(unsigned i = 0; i < mapLayers.size(); i++)
    {
        if(i==playerLayer-1)
        {
            target.draw(player, states);
        }
        target.draw(mapLayers[i], states);
    }
}

void Level::parseLevelInfo(std::__cxx11::string levelName)
{
    int levelWidth, levelHeight, tileWidth, tileHeight, layerNumber = 0;
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
            layerNumber++;
            int pos = curLine.find("name=");
            std::string layerName = curLine.substr(pos+6, curLine.find('\"', pos+6)-pos-6);
            while (curLine.find('<')!=std::string::npos)
            {
                std::getline(fin, curLine);
            }
            int *ln = new int[levelWidth*levelHeight];
            for(int i = 0; i < levelWidth * levelHeight; i++)
            {
                ln[i] = 0;
            }
            int *it = ln;
            for(int i = 0; i < levelWidth; i++)
            {
                for(auto pos = curLine.begin(); pos != curLine.end(); pos++)
                {
                    if(*pos==',')
                    {
                        ++it;
                    }
                    else
                    {
                        *it = *it * 10 + *pos-'0';
                    }
                }

                std::getline(fin, curLine);
            }
            if(layerName!="Collisions" && layerName != "PlayerLayer")
            {
                TileMap cmap;
                cmap.load("Levels/"+levelName+"/tiles.png", sf::Vector2u(tileWidth, tileHeight),
                          ln,levelWidth, levelHeight);;
                mapLayers.push_back(cmap);
                delete[] ln;
            }
            else if(layerName == "Collisions")
            {
                collisions.resetCollisions(ln, levelWidth, levelHeight, tileWidth, tileHeight);
                delete[]ln;
            }
            else
            {
                playerLayer = layerNumber;
                delete[]ln;
            }
        }

    }
    fin.close();
}

void Level::updateInfo(const float &delta)
{

    player.handleInput(delta, collisions);
    camera.setCenter(player.getPosition().x+16.0, player.getPosition().y+16.0);
    camera.setSize(400,350);
}
