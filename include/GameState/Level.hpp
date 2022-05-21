#pragma once

#include "Engine/EntityManager.hpp"
#include "Engine/PhysicSystem.hpp"
#include "GameState/Player.hpp"
#include "Utility/Sprite.hpp"
#include <string>

class Level
{
public:
    Level(const std::string &levelNum);

    void handleInput();

    void fixedUpdate(float deltaTime);

    void update(float deltaTime);

    void lateUpdate(float deltaTime);

    void draw();

private:
    void updateView();

public:
    EntityManager entMng;

    PhysicSystem physic;

    Player *player;
    sf::Vector2f playerStartPos;

    sf::View view;

    Sprite levelSprite;

    int pickups;
    int chests;

    bool lose;
    bool win;
};