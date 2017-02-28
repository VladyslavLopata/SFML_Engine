#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

#include "level.h"

class Engine
{

public:

    //function for initializing all the gameitems and start the main loop
    void start();

private:

    //main loop itself
    void loop();

    //facilities for drawing staff
    void draw();

    //update the information for the game
    void update();

    //game window
    sf::RenderWindow window;

    //clock to count elapsed time between frames
    sf::Clock timer;

    //class to handle game levels
    Level level;

};

#endif // ENGINE_H
