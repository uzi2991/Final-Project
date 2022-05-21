#pragma once

#include "Utility/Sprite.hpp"
#include "Engine/Component.hpp"

class C_Sprite: public Component
{
public:
    C_Sprite() {}

    bool init() override final;

    void lateUpdate(float deltaTime) override final;

    void draw() override final;

    void setTexture(const std::string& textureId);

    void setTextureRect(int left, int top, int width, int height);

    void setTextureRect(const sf::Vector2i &rectPosition, const sf::Vector2i &rectSize);

    void setTextureRect(const sf::IntRect &rect);

private:
    Sprite sprite;
};