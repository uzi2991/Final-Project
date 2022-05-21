#include "MenuState/ChoseCharacterState.hpp"
#include "Engine/SharedContext.hpp"
#include "MenuState/MenuState.hpp"
#include "json/json.h"
#include <fstream>
#include <iostream>

#define SETTINGS_FILEPATH "../res/settings.json"
#define MASK_DUDE_FILEPATH "../res/Graphics/Player/Mask Dude/Idle (32x32).png"
#define NINJA_FROG_FILEPATH "../res/Graphics/Player/Ninja Frog/Idle (32x32).png"
#define PINK_MAN_FILEPATH "../res/Graphics/Player/Pink Man/Idle (32x32).png"
#define VIRTUAL_GUY_FILEPATH "../res/Graphics/Player/Virtual Guy/Idle (32x32).png"

#define ANIM_FPS 20.f
#define CHARACTER_ANIM_NUM_FRAMES 11
#define BACK_BUTTON_SIZE_X 40.f
#define BACK_BUTTON_SIZE_Y 40.f
#define SIDE_BUTTON_DIS_X 150.f

void ChoseCharacterState::init()
{
    System.asset.loadTexture("Mask Dude", MASK_DUDE_FILEPATH);
    System.asset.loadTexture("Ninja Frog", NINJA_FROG_FILEPATH);
    System.asset.loadTexture("Pink Man", PINK_MAN_FILEPATH);
    System.asset.loadTexture("Virtual Guy", VIRTUAL_GUY_FILEPATH);

    this->backButton = std::make_unique<Button>(sf::Vector2f(BACK_BUTTON_SIZE_X, BACK_BUTTON_SIZE_Y), "<");
    this->backButton->setPosition(10.f + BACK_BUTTON_SIZE_X / 2.f, 10.f + BACK_BUTTON_SIZE_Y / 2.f);

    this->nextButton = std::make_unique<Button>(sf::Vector2f(BACK_BUTTON_SIZE_X, BACK_BUTTON_SIZE_Y), ">");
    this->nextButton->setPosition(System.window.getSize().x / 2 + SIDE_BUTTON_DIS_X, System.window.getSize().y / 2);
    this->prevButton = std::make_unique<Button>(sf::Vector2f(BACK_BUTTON_SIZE_X, BACK_BUTTON_SIZE_Y), "<");
    this->prevButton->setPosition(System.window.getSize().x / 2 - SIDE_BUTTON_DIS_X, System.window.getSize().y / 2);

    std::vector<std::string> character{"Mask Dude", "Ninja Frog", "Pink Man", "Virtual Guy"};
    for (const auto &name : character)
    {
        auto &anim = this->characterAnims.emplace_back(System.asset.getTexture(name), CHARACTER_ANIM_NUM_FRAMES, ANIM_FPS);
        anim.setScale(4.f, 4.f);
        anim.setPosition(System.window.getSize().x / 2 - anim.getSize().x / 2, System.window.getSize().y / 2 - anim.getSize().y / 2 - 40.f);

        auto &text = this->characterNames.emplace_back(name, System.asset.getFont("font"));
        auto textRect = text.getGlobalBounds();
        text.setPosition(System.window.getSize().x / 2 - textRect.width / 2, anim.getPosition().y + anim.getSize().y + 20.f);
        text.setFillColor(sf::Color::Black);
    }

    this->read();
}

void ChoseCharacterState::update(float deltaTime)
{
    this->backButton->update(deltaTime);
    this->nextButton->update(deltaTime);
    this->prevButton->update(deltaTime);

    for (auto &anim : this->characterAnims)
    {
        anim.update(deltaTime);
    }

    if (this->prevButton->isClick())
    {
        --this->currentCharacter;
        if (this->currentCharacter < 0)
        {
            this->currentCharacter = this->characterNames.size() - 1;
        }
    }
    else if (this->nextButton->isClick())
    {
        ++this->currentCharacter;
        if (this->currentCharacter >= this->characterNames.size())
        {
            this->currentCharacter = 0;
        }
    }
    else if (this->backButton->isClick())
    {
        this->save();
        System.machine.addState(StateRef(std::make_unique<MenuState>()));
    }
}

void ChoseCharacterState::draw()
{
    System.window.clear(sf::Color::White);

    System.window.setView(System.window.getDefaultView());

    this->characterAnims[this->currentCharacter].draw(System.window);
    System.window.draw(this->characterNames[this->currentCharacter]);

    this->backButton->draw();
    this->nextButton->draw();
    this->prevButton->draw();

    System.window.display();
}

void ChoseCharacterState::read()
{
    Json::Reader reader;
    std::ifstream file(SETTINGS_FILEPATH);
    reader.parse(file, this->settings);

    this->currentCharacter = this->settings["characterId"].asInt();
}

void ChoseCharacterState::save()
{
    this->settings["character"] = std::string(this->characterNames[currentCharacter].getString());
    this->settings["characterId"] = this->currentCharacter;

    std::ofstream outFile(SETTINGS_FILEPATH);
    outFile << this->settings;
}