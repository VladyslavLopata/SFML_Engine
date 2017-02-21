#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include "texturemanager.h"

class Engine {
public:
    Engine();
    void start();

private:
    void loop();
    void draw();
    void update();
    sf::RenderWindow window;
    TextureManager * tManager;
    Player player;
    sf::Clock timer;

};

#endif // ENGINE_H
