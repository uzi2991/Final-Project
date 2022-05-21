#pragma once
#include <string>

class Game
{
public:
    Game(int width, int height, const std::string &title);

    void run();
};