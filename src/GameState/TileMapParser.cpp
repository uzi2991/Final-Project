#include "GameState/TilemapParser.hpp"
#include "GameState/Level.hpp"
#include <fstream>
#include <iostream>
#include "GameState/Terrain.hpp"
#include "GameState/Pickup.hpp"
#include "GameState/Chest.hpp"
#include "GameState/Mushroom.hpp"

#define LEVEL_DATA_FILEPATH_PREFIX "../res/Tilemap/level"

TileMapParser::TileMapParser(Level &level) : level(level)
{
}

void TileMapParser::readLevelData(const std::string &levelNum)
{
    std::ifstream file(LEVEL_DATA_FILEPATH_PREFIX + levelNum + ".json");
    Json::Reader reader;
    reader.parse(file, this->data);

    this->tileSize = this->data["tileheight"].asFloat();

    for (const auto &layer : this->data["layers"])
    {
        auto tag = layer["name"].asString();

        if (tag == "terrain" || tag == "death tile" || tag == "jump platform" || tag == "waypoint" || tag == "end")
        {
            for (const auto &object : layer["objects"])
            {
                sf::Vector2f size(object["width"].asFloat(), object["height"].asFloat());
                sf::Vector2f position(object["x"].asFloat(), object["y"].asFloat());

                auto terrain = this->level.entMng.addEntity<Terrain>(this->level, position, size);
                terrain->tag = tag;
            }
        }
        else if (tag == "pickup")
        {
            for (const auto &object : layer["objects"])
            {
                sf::Vector2f size(object["width"].asFloat(), object["height"].asFloat());
                sf::Vector2f fakePosition(object["x"].asFloat(), object["y"].asFloat());
                sf::Vector2f position = this->convertCoordinate(fakePosition, size);

                auto pickup = this->level.entMng.addEntity<Pickup>(this->level, position);
            }
        }
        else if (tag == "chest")
        {
            for (const auto &object : layer["objects"])
            {
                sf::Vector2f size(object["width"].asFloat(), object["height"].asFloat());
                sf::Vector2f fakePosition(object["x"].asFloat(), object["y"].asFloat());
                sf::Vector2f position = this->convertCoordinate(fakePosition, size);

                this->level.entMng.addEntity<Chest>(this->level, position);
            }
        }
        else if (tag == "player")
        {
            auto object = layer["objects"][0];
            sf::Vector2f size(object["width"].asFloat(), object["height"].asFloat());
            sf::Vector2f fakePosition(object["x"].asFloat(), object["y"].asFloat());
            this->level.playerStartPos = this->convertCoordinate(fakePosition, size);
        }
        else if (tag == "mushroom")
        {
            for (const auto &object : layer["objects"])
            {
                sf::Vector2f size(object["width"].asFloat(), object["height"].asFloat());
                sf::Vector2f fakePosition(object["x"].asFloat(), object["y"].asFloat());
                sf::Vector2f position = this->convertCoordinate(fakePosition, size);

                this->level.entMng.addEntity<Mushroom>(this->level, position);
            }
        }
    }
}

sf::Vector2f TileMapParser::convertCoordinate(const sf::Vector2f &fakePosition, const sf::Vector2f &size)
{
    sf::Vector2f midBottom;
    midBottom.x = fakePosition.x + this->tileSize / 2;
    midBottom.y = fakePosition.y;

    sf::Vector2f position;
    position.x = midBottom.x - size.x / 2;
    position.y = midBottom.y - size.y;

    return position;
}