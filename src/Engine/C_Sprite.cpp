#include "Engine/C_Sprite.hpp"
#include "Engine/SharedContext.hpp"
#include "Engine/Entity.hpp"

bool C_Sprite::init()
{
    return true;
}

void C_Sprite::lateUpdate(float deltaTime)
{
    this->sprite.setPosition(this->entity->transform->position);
    this->sprite.setScale(this->entity->transform->scale);
    this->sprite.setRotation(this->entity->transform->rotation);
    this->sprite.setFlipX(this->entity->transform->flipX);
    this->sprite.setFlipY(this->entity->transform->flipY);
}

void C_Sprite::draw() 
{
    this->sprite.draw(System.window);
}

void C_Sprite::setTexture(const std::string& textureId)
{
    this->sprite.setTexture(System.asset.getTexture(textureId));
}

void C_Sprite::setTextureRect(int left, int top, int width, int height)
{
    this->sprite.setTextureRect(left, top, width, height);
}

void C_Sprite::setTextureRect(const sf::Vector2i &rectPosition, const sf::Vector2i &rectSize)
{
    this->sprite.setTextureRect(rectPosition, rectSize);
}

void C_Sprite::setTextureRect(const sf::IntRect &rect)
{
    this->sprite.setTextureRect(rect);
}
