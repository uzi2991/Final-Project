#include "Engine/Transform.hpp"

bool Transform::init()
{
    this->position.x = 0.f;
    this->position.y = 0.f;

    this->scale.x = 1.f;
    this->scale.y = 1.f;

    this->rotation = 0.f;
    
    this->flipX = false;
    this->flipY = false;

    return true;
}

void Transform::move(float offsetX, float offsetY)
{
    this->position.x += offsetX;
    this->position.y += offsetY;
}

void Transform::move(const sf::Vector2f& offset)
{
    this->move(offset.x, offset.y);
}