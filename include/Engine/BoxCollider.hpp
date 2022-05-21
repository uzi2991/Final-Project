#pragma once

#include "Engine/Component.hpp"
#include "SFML/Graphics.hpp"

struct Manifold
{
    Entity* other;
    sf::Vector2f resolve;
};

class BoxCollider : public Component
{
public:
    BoxCollider() {}

    BoxCollider(float width, float height);

    BoxCollider(const sf::Vector2f &size);

    const sf::FloatRect &getAABB();

    Manifold getCollisionInfo(BoxCollider* otherBox);

    void setSize(const sf::Vector2f &size);

    void setSize(float width, float height);

    void setOffset(const sf::Vector2f& offset);

private:
    void setPosition();
    sf::Vector2f getCenter() const;
    sf::Vector2f getHalfSize() const;

private:
    sf::FloatRect AABB;
    sf::Vector2f offset;
};