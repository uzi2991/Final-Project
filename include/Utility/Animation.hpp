#pragma once

#include "Utility/Sprite.hpp"
#include "Utility/SpriteSheet.hpp"

/*
    Animation from single row SpriteSheet
*/
class Animation
{
public:
    Animation() {}

    Animation(const sf::Texture &texture, int numFrames, float fps, bool looped = true);

    void update(float deltaTime);

    void draw(sf::RenderTarget& target);

    void setTexture(const sf::Texture &texture, int numFrames, float fps, bool looped = true);

    void setPosition(float x, float y);

    void setPosition(const sf::Vector2f &position);

    void setScale(const sf::Vector2f& scale);

    void setScale(float scaleX, float scaleY);

    void setRotation(float rotation);

    void setFlipX(bool flipX);

    void setFlipY(bool flipY);

    sf::Vector2f getPosition() const;

    sf::Vector2f getSize() const;

    void reset();

    bool isDone() const;

private:
    Sprite sprite;

    SpriteSheet sheet;

    int numFrames;
    int curFrame;

    float frameDuration;
    float progess;

    bool flipX, flipY;
    
    bool looped;

    bool done;
};