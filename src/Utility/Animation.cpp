#include "Utility/Animation.hpp"
#include <cmath>
#include <iostream>

Animation::Animation(const sf::Texture &texture, int numFrames, float fps, bool looped)
{
    this->setTexture(texture, numFrames, fps, looped);
}

void Animation::update(float deltaTime)
{
    if (this->done)
    {
        return;
    }

    this->progess += deltaTime;
    if (this->progess >= this->frameDuration)
    {
        this->curFrame += this->progess / this->frameDuration;
        if (this->curFrame >= this->numFrames)
        {
            if (this->looped)
            {
                this->curFrame = this->curFrame % this->numFrames;
            }
            else
            {
                this->curFrame = this->numFrames - 1;
                this->done = true;
            }
        }
        this->progess = fmod(this->progess, this->frameDuration);

        this->sprite.setTextureRect(this->sheet.getSpriteAt(this->curFrame));
    }

    this->sprite.setFlipX(this->flipX);
    this->sprite.setFlipY(this->flipY);
}

void Animation::draw(sf::RenderTarget &target)
{
    this->sprite.draw(target);
}

void Animation::setTexture(const sf::Texture &texture, int numFrames, float fps, bool looped)
{
    this->numFrames = numFrames;
    this->curFrame = 0;
    this->frameDuration = 1.f / fps;
    this->progess = 0.f;

    sf::Vector2i textureSize(texture.getSize());
    sf::Vector2i spriteSize(textureSize.x / numFrames, textureSize.y);
    this->sheet.setSheet(textureSize, spriteSize);

    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(this->sheet.getSpriteAt(0));

    this->flipX = false;
    this->flipY = false;
    this->looped = looped;
    this->done = false;
}
void Animation::setPosition(float x, float y)
{
    this->sprite.setPosition(x, y);
}

void Animation::setPosition(const sf::Vector2f &position)
{
    this->sprite.setPosition(position);
}

void Animation::setScale(const sf::Vector2f &scale)
{
    this->sprite.setScale(scale);
}

void Animation::setScale(float scaleX, float scaleY)
{
    this->sprite.setScale(scaleX, scaleY);
}

void Animation::setRotation(float rotation)
{
    this->sprite.setRotation(rotation);
}

void Animation::setFlipX(bool flipX)
{
    this->flipX = flipX;
}

void Animation::setFlipY(bool flipY)
{
    this->flipY = flipY;
}

sf::Vector2f Animation::getPosition() const
{
    return this->sprite.getPosition();
}

sf::Vector2f Animation::getSize() const
{
    return this->sprite.getSize();
}

void Animation::reset()
{
    this->curFrame = 0;
    this->progess = 0.f;

    this->done = false;

    this->sprite.setTextureRect(this->sheet.getSpriteAt(0));
}

bool Animation::isDone() const
{
    return this->done;
}