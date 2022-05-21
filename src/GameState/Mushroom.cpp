#include "GameState/Level.hpp"
#include "GameState/Mushroom.hpp"
#include "Engine/C_Animation.hpp"
#include "Engine/SharedContext.hpp"
#include "Engine/BoxCollider.hpp"

#define RUN_NUM_FRAMES 16
#define ANIM_FPS 20.f
#define SPEED 80.f

void Mushroom::init()
{
    this->tag = "mushroom";
    this->transform->position = this->position;

    auto animations = this->addComponent<C_Animation>();

    Animation runAnim(System.asset.getTexture("mushroom run"), RUN_NUM_FRAMES, ANIM_FPS);
    animations->addAnimation("running", runAnim);

    animations->switchAnimation("running");

    auto box = this->addComponent<BoxCollider>();
    box->setOffset(sf::Vector2f(3.f, 11.f));
    box->setSize(26.f, 21.f);

    this->body = this->addComponent<RigidBody>();

    this->level.physic.addObject(this->body, false);

    this->body->velocity.x = SPEED;
}

void Mushroom::onCollision(Entity *other)
{
    if (other->tag == "waypoint")
    {
        this->body->velocity.x *= -1.f;
    }
}

void Mushroom::lateUpdate(float deltaTime)
{
    if (this->body->velocity.x > 0.f)
    {
        this->transform->flipX = true;
    }
    else if (this->body->velocity.x < 0.f)
    {
        this->transform->flipX = false;
    }

    this->Entity::lateUpdate(deltaTime);
}