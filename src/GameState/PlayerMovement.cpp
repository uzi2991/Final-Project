#include "GameState/PlayerMovement.hpp"
#include "Engine/Entity.hpp"
#include "Engine/SharedContext.hpp"
#include <iostream>

#define MOVE_SPEED 200.f
#define GRAVITY 600.f
#define JUMP_SPEED 320.f
#define MAX_JUMPS 2

bool PlayerMovement::init()
{
    this->body = this->entity->getComponent<RigidBody>();
    this->body->acceleration.y = GRAVITY;
    this->animations = this->entity->getComponent<C_Animation>();

    this->moveSpeed = MOVE_SPEED;
    this->jumpSpeed = JUMP_SPEED;

    this->maxJumps = 2;
    this->jumpLeft = 0;
    this->isOnGround = false;

    this->isFacingLeft = false;

    this->jumpSound.setBuffer(System.asset.getSoundBuffer("jump"));

    return true;
}

void PlayerMovement::update(float deltaTime)
{
    if (System.input.isKeyPressed(Input::Key::A))
    {
        this->body->velocity.x = -this->moveSpeed;
    }
    else if (System.input.isKeyPressed(Input::Key::D))
    {
        this->body->velocity.x = this->moveSpeed;
    }
    else
    {
        this->body->velocity.x = 0.f;
    }

    if (System.input.isKeyDown(Input::Key::W) && this->jumpLeft > 0)
    {
        this->body->velocity.y = -this->jumpSpeed;
        --this->jumpLeft;
        this->jumpSound.play();
    }

    if (this->isOnGround && (this->body->velocity.y != 0.f))
    {
        this->isOnGround = false;
    }

    if (this->body->velocity.x > 0.f)
    {
        this->isFacingLeft = false;
    }
    else if (this->body->velocity.x < 0.f)
    {
        this->isFacingLeft = true;
    }

    this->entity->transform->flipX = this->isFacingLeft;

    if (this->isOnGround)
    {
        if (this->body->velocity.x != 0.f)
        {
            this->animations->switchAnimation("running");
        }
        else
        {
            this->animations->switchAnimation("idle");
        }
    }
    else
    {
        if (this->body->velocity.y < 0.f)
        {
            if (this->jumpLeft == 0)
            {
                this->animations->switchAnimation("double jumping");
            }
            else
            {
                this->animations->switchAnimation("jumping");
            }
        }
        else
        {
            this->animations->switchAnimation("falling");
        }
    }
}

void PlayerMovement::collisionWithTerrain(Entity *terrain)
{
    Manifold m = this->entity->getComponent<BoxCollider>()->getCollisionInfo(terrain->getComponent<BoxCollider>());
    this->entity->transform->move(m.resolve);

    if (m.resolve.y < 0.f) // Bottom
    {
        this->body->velocity.y = 0.f;
        this->isOnGround = true;
        this->jumpLeft = this->maxJumps;
    }
    else if (m.resolve.y > 0.f) // Top
    {
        this->body->velocity.y = 0.f;
    }
}

void PlayerMovement::collisionWithJumpPlatform(Entity* jumpPlatform)
{
    auto playerBox = this->entity->getComponent<BoxCollider>();
    auto platformBox = jumpPlatform->getComponent<BoxCollider>();
    Manifold m = playerBox->getCollisionInfo(platformBox);
 

    if (m.resolve.y < 0.f && this->body->velocity.y > 0.f)
    {
        this->body->velocity.y = 0.f;
        this->isOnGround = true;
        this->jumpLeft = this->maxJumps;
        this->entity->transform->move(m.resolve);   
    }
}

void PlayerMovement::collisionWithEnemy(Entity* enemy)
{

}