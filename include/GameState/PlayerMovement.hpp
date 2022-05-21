#pragma once

#include "Engine/RigidBody.hpp"
#include "SFML/Audio.hpp"
#include "Engine/C_Animation.hpp"

class PlayerMovement: public Component
{
public:
    bool init() override final;

    void update(float deltaTime) override;

    void collisionWithTerrain(Entity* terrain);

    void collisionWithJumpPlatform(Entity* jumpPlatform);

    void collisionWithEnemy(Entity* enemy);

public:
    float jumpSpeed;
    
private:
    RigidBody* body;
    C_Animation* animations;

    float moveSpeed;

    int jumpLeft;
    int maxJumps;
    bool isOnGround;

    bool isFacingLeft;

    sf::Sound jumpSound;
};
