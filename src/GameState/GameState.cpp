#include "GameState/GameState.hpp"
#include "Engine/SharedContext.hpp"
#include "GameOverState/GameOverState.hpp"
#include <iostream>
#include <regex>
#include <fstream>
#include <json/json.h>

#define PLAYER_IDLE_FILEPATH "../res/Graphics/Player/<PLAYER>/Idle (32x32).png"
#define PLAYER_RUNNING_FILEPATH "../res/Graphics/Player/<PLAYER>/Run (32x32).png"
#define PLAYER_JUMPING_FILEPATH "../res/Graphics/Player/<PLAYER>/Jump (32x32).png"
#define PLAYER_FALLING_FILEPATH "../res/Graphics/Player/<PLAYER>/Fall (32x32).png"
#define PLAYER_DOUBLE_JUMPING_FILEPATH "../res/Graphics/Player/<PLAYER>/Double Jump (32x32).png"

#define MUSHROOM_RUN_FILEPATH "../res/Graphics/Mushroom/Run (32x32).png"
#define MUSHROOM_HIT_FILEPATH "../res/Graphics/Mushroom/Hit (32x32).png"

#define LEVEL1_FILEPATH "../res/Graphics/Level/level1.png"
#define LEVEL2_FILEPATH "../res/Graphics/Level/level2.png"

#define PICKUP_FILEPATH "../res/Graphics/Fruit/Apple.png"
#define CHEST_IDLE_FILEPATH "../res/Graphics/Chest/idle.png"
#define CHEST_OPEN_FILEPATH "../res/Graphics/Chest/open.png"
#define BACKGROUND_FILEPATH "../res/Graphics/Background/brown-background.png"
#define SETTINGS_FILEPATH "../res/settings.json"



void GameState::init()
{
    Json::Value settings;
    Json::Reader reader;
    std::ifstream file(SETTINGS_FILEPATH);
    reader.parse(file, settings);

    const std::string playerName = settings["character"].asString();
    std::regex playerRegex("<PLAYER>");

    System.asset.loadTexture("player idle",
                             std::regex_replace(PLAYER_IDLE_FILEPATH, playerRegex, playerName));
    System.asset.loadTexture("player running",
                             std::regex_replace(PLAYER_RUNNING_FILEPATH, playerRegex, playerName));
    System.asset.loadTexture("player jumping",
                             std::regex_replace(PLAYER_JUMPING_FILEPATH, playerRegex, playerName));
    System.asset.loadTexture("player falling",
                             std::regex_replace(PLAYER_FALLING_FILEPATH, playerRegex, playerName));
    System.asset.loadTexture("player double jumping",
                             std::regex_replace(PLAYER_DOUBLE_JUMPING_FILEPATH, playerRegex, playerName));

    System.asset.loadTexture("mushroom run", MUSHROOM_RUN_FILEPATH);
    System.asset.loadTexture("mushroom hit", MUSHROOM_HIT_FILEPATH);

    System.asset.loadTexture("pickup", PICKUP_FILEPATH);

    System.asset.loadTexture("chest idle", CHEST_IDLE_FILEPATH);
    System.asset.loadTexture("chest open", CHEST_OPEN_FILEPATH);

    System.asset.loadTexture("background", BACKGROUND_FILEPATH);

    System.asset.loadTexture("level 1", LEVEL1_FILEPATH);
    System.asset.loadTexture("level 2", LEVEL2_FILEPATH);

    this->level = std::make_unique<Level>(this->levelNum);

    this->hud = std::make_unique<GameHUD>();

    this->background = std::make_unique<Background>();

    this->backgroundMusic.setBuffer(System.asset.getSoundBuffer("main theme"));
    this->backgroundMusic.setLoop(true);
    this->backgroundMusic.play();
}

void GameState::destroy()
{
    System.asset.unLoadTexture("player idle");
    System.asset.unLoadTexture("player running");
    System.asset.unLoadTexture("player jumping");
    System.asset.unLoadTexture("player falling");
    System.asset.unLoadTexture("player double jumping");

    this->backgroundMusic.stop();
}

void GameState::handleInput()
{
    this->level->handleInput();
}

void GameState::fixedUpdate(float deltaTime)
{
    this->level->fixedUpdate(deltaTime);
}

void GameState::update(float deltaTime)
{
    if (this->level->lose)
    {
        System.machine.addState(StateRef(std::make_unique<GameOverState>(false)));
    }
    else if (this->level->win)
    {
        System.machine.addState(StateRef(std::make_unique<GameOverState>(true)));
    }
    
    this->level->update(deltaTime);
}

void GameState::lateUpdate(float deltaTime)
{
    this->level->lateUpdate(deltaTime);

    this->hud->setChests(this->level->chests);
    this->hud->setPickups(this->level->pickups);
    this->hud->update(deltaTime);
    this->background->update(deltaTime);
}

void GameState::draw()
{
    System.window.clear(sf::Color::White);

    this->background->draw();

    this->level->draw();

    this->hud->draw();

    System.window.display();

    System.window.setView(System.window.getDefaultView());
}