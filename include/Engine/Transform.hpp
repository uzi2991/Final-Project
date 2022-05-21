#pragma once

#include "Engine/Component.hpp"
#include "SFML/Graphics.hpp"

class Transform: public Component
{
public:
    bool init() override final;

    void move(const sf::Vector2f& offset);

    void move(float offsetX, float offsetY);

    sf::Vector2f position;
    sf::Vector2f scale;
    float rotation;
    bool flipX;
    bool flipY;
};