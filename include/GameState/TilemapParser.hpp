#pragma once

#include "json/json.h"
#include "SFML/Graphics.hpp"
#include <string>

class Level;

class TileMapParser
{
public:
    TileMapParser(Level &level);

    void readLevelData(const std::string &levelNum);

private:
    sf::Vector2f convertCoordinate(const sf::Vector2f &fakePosition, const sf::Vector2f &size);

private:
    Level &level;

    Json::Value data;

    float tileSize;
};