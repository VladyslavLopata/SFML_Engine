#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include "level.h"

class Engine {
public:
    Engine();
    void start();

private:
    void loop();
    void draw();
    void update();
    sf::RenderWindow window;
    Player player;
    sf::Clock timer;
    Level level;

};

#endif // ENGINE_H
