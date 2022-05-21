#pragma once

#include "Engine/Entity.hpp"

class Level;

class Terrain: public Entity
{
public:
    Terrain(Level& level, const sf::Vector2f& position, const sf::Vector2f& size);

    void init() override final;

private:
    Level& level;

    sf::Vector2f position;
    sf::Vector2f size;

};