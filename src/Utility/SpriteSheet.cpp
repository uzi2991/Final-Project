#include "Utility/SpriteSheet.hpp"

SpriteSheet::SpriteSheet(const sf::Vector2i &textureSize, const sf::Vector2i &spriteSize)
{
    this->setSheet(textureSize, spriteSize);
}

void SpriteSheet::setSheet(const sf::Vector2i &textureSize, const sf::Vector2i &spriteSize)
{
    this->numRows = textureSize.y / spriteSize.y;
    this->numCols = textureSize.x / spriteSize.x;
    this->spriteSize = spriteSize;
}

sf::IntRect SpriteSheet::getSpriteAt(int index) const
{
    int rowIdx = index / this->numCols;
    int colIdx = index % this->numCols;

    return sf::IntRect(sf::Vector2i(colIdx * this->spriteSize.x, rowIdx * this->spriteSize.y), this->spriteSize);
}