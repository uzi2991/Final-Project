#include "Utility/Sprite.hpp"

Sprite::Sprite()
{
    this->textureRect = sf::IntRect(0, 0, 0, 0);
    this->flipX = false;
    this->flipY = false;
}

Sprite::Sprite(const sf::Texture &texture)
{
    this->setTexture(texture);
}

void Sprite::draw(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}

void Sprite::setTexture(const sf::Texture &texture)
{
    this->sprite.setTexture(texture);
    this->setTextureRect(this->sprite.getTextureRect());
}

void Sprite::setTextureRect(int left, int top, int width, int height)
{
    this->setTextureRect(sf::IntRect(left, top, width, height));
}

void Sprite::setTextureRect(const sf::Vector2i &rectPosition, const sf::Vector2i &rectSize)
{
    this->setTextureRect(sf::IntRect(rectPosition, rectSize));
}

void Sprite::setTextureRect(const sf::IntRect &rect)
{
    this->textureRect = rect;
    this->sprite.setTextureRect(rect);
    this->flipX = this->flipY = false;
}

void Sprite::setOrigin(float x, float y)
{
    this->sprite.setOrigin(x, y);
}

void Sprite::setOrigin(const sf::Vector2f &origin)
{
    this->sprite.setOrigin(origin);
}

void Sprite::setPosition(float x, float y)
{
    this->sprite.setPosition(x, y);
}

void Sprite::setPosition(const sf::Vector2f &position)
{
    this->sprite.setPosition(position);
}

void Sprite::setScale(const sf::Vector2f &scale)
{
    this->sprite.setScale(scale);
}

void Sprite::setScale(float scaleX, float scaleY)
{
    this->sprite.setScale(scaleX, scaleY);
}

void Sprite::setRotation(float rotation)
{
    this->sprite.setRotation(rotation);
}

void Sprite::setFlipX(bool flipX)
{
    if (this->flipX == flipX)
    {
        return;
    }

    this->flipX = flipX;
    auto [left, top, width, height] = this->textureRect;
    if (flipX)
    {
        this->sprite.setTextureRect(sf::IntRect(left + width, top, -width, height));
    }
    else
    {
        this->sprite.setTextureRect(sf::IntRect(left, top, width, height));
    }
}

void Sprite::setFlipY(bool flipY)
{
    if (this->flipY == flipY)
    {
        return;
    }

    this->flipY = flipY;
    auto [left, top, width, height] = this->textureRect;
    if (flipY)
    {
        this->sprite.setTextureRect(sf::IntRect(left, top + height, width, -height));
    }
    else
    {
        this->sprite.setTextureRect(sf::IntRect(left, top, width, height));
    }
}

sf::Vector2f Sprite::getPosition() const
{
    return this->sprite.getPosition();
}

sf::Vector2f Sprite::getSize() const
{
    return sf::Vector2f(this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height);
}