#include "GameState/Pickup.hpp"
#include "Engine/C_Animation.hpp"
#include "Engine/SharedContext.hpp"
#include "Engine/BoxCollider.hpp"
#include "Engine/RigidBody.hpp"
#include "GameState/Level.hpp"

#define ANIM_NUM_FRAMES 17
#define ANIM_FPS 20.f
#define SIZE_X 20.f
#define SIZE_Y 20.f

Pickup::Pickup(Level& level, const sf::Vector2f &position) : level(level)
{
    this->position = position;
}

void Pickup::init()
{
    this->transform->position = this->position;
    this->tag = "pickup";

    auto animations = this->addComponent<C_Animation>();
    Animation idleAnim(System.asset.getTexture("pickup"), ANIM_NUM_FRAMES, ANIM_FPS);
    animations->addAnimation("idle", idleAnim);

    animations->switchAnimation("idle");

    this->addComponent<BoxCollider>(SIZE_X, SIZE_Y);

    this->level.physic.addObject(this->addComponent<RigidBody>());
}

void Pickup::onCollision(Entity *other)
{
}