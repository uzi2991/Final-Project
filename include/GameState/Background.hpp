#pragma once
#include "Utility/Sprite.hpp"

class Background
{
public:
    Background();

    void update(float deltaTime);

    void draw();

private:
    Sprite sprite1, sprite2;

    sf::View view;

    float height;

    const float speed = 100.f;

    float y1, y2;
};