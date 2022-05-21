#pragma once

#include "Engine/Entity.hpp"
#include "Engine/RigidBody.hpp"

class Level;

class Mushroom: public Entity
{
public:
    Mushroom(Level& level, const sf::Vector2f& position): level(level), position(position) {}

    void init() override final;

    void lateUpdate(float deltaTime) override final;
    
    void onCollision(Entity* other) override final;

private:
    Level& level;

    sf::Vector2f position;

    RigidBody* body;

};