#pragma once

#include "Engine/Transform.hpp"
#include "Engine/BoxCollider.hpp"

class RigidBody: public Component
{
public:
    RigidBody();

    bool init() override final;

    void fixedUpdate(float deltaTime) override final;

    bool isCollide(RigidBody* other);

public:
    sf::Vector2f velocity;
    sf::Vector2f acceleration;

private:
    Transform* transform;
    BoxCollider* collider;
};