#pragma once

#include "SFML/Graphics.hpp"

/*
    SpriteSheet Class
    Only stores information,
    Not stores texture
*/
class SpriteSheet
{
public:
    SpriteSheet() {}

    SpriteSheet(const sf::Vector2i& textureSize, const sf::Vector2i& spriteSize);

    void setSheet(const sf::Vector2i& textureSize, const sf::Vector2i& spriteSize);

    // return the texture rect of sprite at index 
    sf::IntRect getSpriteAt(int index) const;

private:
    int numRows, numCols;
    sf::Vector2i spriteSize;
};