#include "Engine/Game.hpp"
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define TITLE "Pi's Adventure"

int main()
{
    Game game(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    
    game.run();
}


