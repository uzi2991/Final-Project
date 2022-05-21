#include "GameState/Player.hpp"
#include "GameState/Level.hpp"
#include "Engine/SharedContext.hpp"
#include "GameState/PlayerMovement.hpp"
#include "Engine/C_Animation.hpp"
#include <iostream>

#define IDLE_NUM_FRAMES 11
#define RUNNING_NUM_FRAMES 12
#define JUMPING_NUM_FRAMES 1
#define DOUBLE_JUMPING_NUM_FRAMES 6
#define FALLING_NUM_FRAMES 1
#define ANIM_FPS 20.f
#define PLAYER_SIZE_X 32.f
#define PLAYER_SIZE_Y 32.f

Player::Player(Level &level) : level(level), Entity()
{
}

void Player::init()
{
    this->tag = "player";
    this->transform->position = this->level.playerStartPos;

    auto playerAnim = this->addComponent<C_Animation>();

    Animation idleAnim(System.asset.getTexture("player idle"), IDLE_NUM_FRAMES, ANIM_FPS);
    playerAnim->addAnimation("idle", idleAnim);

    Animation runningAnim(System.asset.getTexture("player running"), RUNNING_NUM_FRAMES, ANIM_FPS);
    playerAnim->addAnimation("running", runningAnim);

    Animation jumpingAnim(System.asset.getTexture("player jumping"), JUMPING_NUM_FRAMES, ANIM_FPS);
    playerAnim->addAnimation("jumping", jumpingAnim);

    Animation fallingAnim(System.asset.getTexture("player falling"), FALLING_NUM_FRAMES, ANIM_FPS);
    playerAnim->addAnimation("falling", fallingAnim);

    Animation doubleJumpingAnim(System.asset.getTexture("player double jumping"), DOUBLE_JUMPING_NUM_FRAMES, ANIM_FPS);
    playerAnim->addAnimation("double jumping", doubleJumpingAnim);

    playerAnim->switchAnimation("falling");

    this->addComponent<BoxCollider>(PLAYER_SIZE_X, PLAYER_SIZE_Y);
    this->level.physic.addObject(this->addComponent<RigidBody>(), false);
    this->addComponent<PlayerMovement>();
}

void Player::onCollision(Entity *other)
{
    if (other->tag == "terrain")
    {
        this->getComponent<PlayerMovement>()->collisionWithTerrain(other);
    }
    else if (other->tag == "jump platform")
    {
        this->getComponent<PlayerMovement>()->collisionWithJumpPlatform(other);
    }
    else if (other->tag == "death tile")
    {
        this->level.lose = true;
    }
    else if (other->tag == "pickup")
    {
        other->destroy();
        ++this->level.pickups;
    }
    else if (other->tag == "mushroom")
    {
        Manifold m = this->getComponent<BoxCollider>()->getCollisionInfo(other->getComponent<BoxCollider>());

        if (m.resolve.y < 0.f) // Bottom
        {
            this->getComponent<RigidBody>()->velocity.y = -this->getComponent<PlayerMovement>()->jumpSpeed;
            other->destroy();
        }
        else
        {
            this->level.lose = true;
        }
    }
    else if (other->tag == "end")
    {
        this->level.win = true;
    }
}
