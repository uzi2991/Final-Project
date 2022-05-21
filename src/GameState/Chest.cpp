#include "GameState/Chest.hpp"
#include "GameState/Level.hpp"
#include "Engine/C_Animation.hpp"
#include "Engine/SharedContext.hpp"

#define IDLE_NUM_FRAMES 1
#define OPEN_NUM_FRAMES 7
#define ANIM_FPS 20.f
#define SIZE_X 32.f
#define SIZE_Y 32.f

Chest::Chest(Level &level, const sf::Vector2f &position) : level(level), position(position)
{
}

void Chest::init()
{
    this->tag = "chest";
    this->transform->position = this->position;

    auto animations = this->addComponent<C_Animation>();

    Animation idleAnim(System.asset.getTexture("chest idle"), IDLE_NUM_FRAMES, ANIM_FPS);
    animations->addAnimation("idle", idleAnim);

    Animation openAnim(System.asset.getTexture("chest open"), OPEN_NUM_FRAMES, ANIM_FPS, false);
    animations->addAnimation("open", openAnim);

    animations->switchAnimation("idle");

    this->addComponent<BoxCollider>(SIZE_X, SIZE_Y);
    this->level.physic.addObject(this->addComponent<RigidBody>());

    this->isOpen = false;
}

void Chest::onCollision(Entity *other)
{
    if (other->tag == "player" && !this->isOpen)
    {
        this->getComponent<C_Animation>()->switchAnimation("open");

        this->isOpen = true;

        ++this->level.chests;
    }
}