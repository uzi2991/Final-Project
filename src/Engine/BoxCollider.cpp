#include "Engine/BoxCollider.hpp"
#include "Engine/Entity.hpp"
#include <iostream>

BoxCollider::BoxCollider(float width, float height)
{
    this->setSize(width, height);
}

BoxCollider::BoxCollider(const sf::Vector2f &size)
{
    this->setSize(size);
}

const sf::FloatRect &BoxCollider::getAABB()
{
    this->setPosition();
    return this->AABB;
}

Manifold BoxCollider::getCollisionInfo(BoxCollider *otherBox)
{
    Manifold m;
    m.other = otherBox->entity;

    sf::Vector2f dis = this->getCenter() - otherBox->getCenter();

    sf::Vector2f overlap;
    overlap.x = this->getHalfSize().x + otherBox->getHalfSize().x - std::abs(dis.x);
    overlap.y = this->getHalfSize().y + otherBox->getHalfSize().y - std::abs(dis.y);

    if (overlap.x < overlap.y)
    {
        if (dis.x > 0)
        {
            m.resolve.x = overlap.x;
        }
        else
        {
            m.resolve.x = -overlap.x;
        }
    }
    else
    {
        if (dis.y > 0)
        {
            m.resolve.y = overlap.y;
        }
        else
        {
            m.resolve.y = -overlap.y;
        }
    }

    return m;
}

void BoxCollider::setSize(const sf::Vector2f &size)
{
    this->AABB.width = size.x;
    this->AABB.height = size.y;
}

void BoxCollider::setSize(float width, float height)
{
    this->AABB.width = width;
    this->AABB.height = height;
}

void BoxCollider::setPosition()
{
    this->AABB.left = this->entity->transform->position.x + this->offset.x;
    this->AABB.top = this->entity->transform->position.y + this->offset.y;
}

sf::Vector2f BoxCollider::getCenter() const
{
    return sf::Vector2f(this->AABB.left + this->AABB.width / 2, this->AABB.top + this->AABB.height / 2);
}
sf::Vector2f BoxCollider::getHalfSize() const
{
    return sf::Vector2f(this->AABB.width / 2, this->AABB.height / 2);
}

void BoxCollider::setOffset(const sf::Vector2f& offset)
{
    this->offset = offset;
}