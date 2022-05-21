#pragma once

#include "SFML/Graphics.hpp"

class Sprite
{
public:
    Sprite();
    
    Sprite(const sf::Texture &texture);

    void draw(sf::RenderTarget& target);

    void setTexture(const sf::Texture &texture);

    void setTextureRect(int left, int top, int width, int height);

    void setTextureRect(const sf::Vector2i &rectPosition, const sf::Vector2i &rectSize);

    void setTextureRect(const sf::IntRect &rect);

    void setOrigin(float x, float y);

    void setOrigin(const sf::Vector2f& origin);

    void setPosition(float x, float y);

    void setPosition(const sf::Vector2f &position);

    void setScale(const sf::Vector2f& scale);

    void setScale(float scaleX, float scaleY);

    void setRotation(float rotation);

    void setFlipX(bool flipX);

    void setFlipY(bool flipY);

    sf::Vector2f getPosition() const;

    sf::Vector2f getSize() const;

private:
    sf::Sprite sprite;
    bool flipX;
    bool flipY;

    // original textureRect
    sf::IntRect textureRect;
};