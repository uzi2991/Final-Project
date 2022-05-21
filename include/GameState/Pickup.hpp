#pragma once

#include "Engine/Entity.hpp"

class Level;

class Pickup: public Entity
{
public:
    Pickup(Level& level, const sf::Vector2f& position);

    void init() override final;
    
    void onCollision(Entity* other) override final;

private:
    Level& level;

    sf::Vector2f position;
};