#include "Engine/C_Animation.hpp"
#include "Engine/Entity.hpp"
#include "Engine/SharedContext.hpp"

void C_Animation::lateUpdate(float deltaTime)
{
    this->animations[currentAnimation].update(deltaTime);

    this->animations[currentAnimation].setPosition(this->entity->transform->position);
    this->animations[currentAnimation].setScale(this->entity->transform->scale);
    this->animations[currentAnimation].setRotation(this->entity->transform->rotation);

    this->animations[currentAnimation].setFlipX(this->entity->transform->flipX);
    this->animations[currentAnimation].setFlipY(this->entity->transform->flipY);
}

void C_Animation::draw()
{
    this->animations[currentAnimation].draw(System.window);
}

void C_Animation::addAnimation(const std::string &name, const Animation &animation)
{
    this->animations[name] = animation;
}

void C_Animation::switchAnimation(const std::string &name)
{
    if (this->currentAnimation != name)
    {
        this->currentAnimation = name;
        this->animations[name].reset();
    }
}