#pragma once

#include "Engine/Entity.hpp"

class Level;

class Player: public Entity
{
public:
    Player(Level& level);

    void init() override final;

    void onCollision(Entity* other) override final;

private:
    Level& level;
};