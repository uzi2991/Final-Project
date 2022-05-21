#pragma once

#include "SFML/Graphics.hpp"

class GameHUD
{
public:
    GameHUD();

    void update(float deltaTime);

    void setPickups(int pickups);
    
    void setChests(int chests);

    void draw();

private:
    float progess;

    const float delay = 0.25f;

    int pickups;

    int chests;

    sf::View view;

    sf::Text fpsText;

    sf::Text pickupText;
    
    sf::Text chestText;
};