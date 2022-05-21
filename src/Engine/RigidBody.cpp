#include "Engine/RigidBody.hpp"
#include "Engine/Entity.hpp"
#include <algorithm>
#include <iostream>

#define MIN_VELOCITY -600.f
#define MAX_VELOCITY 600.f

RigidBody::RigidBody()
{
    this->velocity = sf::Vector2(0.f, 0.f);
    this->acceleration = sf::Vector2f(0.f, 0.f);
}

bool RigidBody::init()
{
    this->transform = this->entity->transform;
    this->collider = this->entity->getComponent<BoxCollider>();

    return true;
}

void RigidBody::fixedUpdate(float deltaTime)
{
    this->velocity += this->acceleration * deltaTime;
    this->transform->move(this->velocity * deltaTime);
}

bool RigidBody::isCollide(RigidBody* other)
{
    return this->collider->getAABB().intersects(other->collider->getAABB());
}
