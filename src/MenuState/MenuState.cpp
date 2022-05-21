#include "MenuState/MenuState.hpp"
#include "MenuState/ChoseLevelState.hpp"
#include "MenuState/ChoseCharacterState.hpp"
#include "MenuState/TutorialState.hpp"
#include "Engine/SharedContext.hpp"
#include <iostream>

#define BUTTON_SIZE_X 300
#define BUTTON_SIZE_Y 50
#define BUTTON_DISTANCE 25
#define NUM_BUTTONS 2

void MenuState::init()
{    
    float totalHeight = NUM_BUTTONS * BUTTON_SIZE_Y + (NUM_BUTTONS - 1) * BUTTON_DISTANCE;
    float firstPos = System.window.getSize().y / 2 - totalHeight / 2 + BUTTON_SIZE_Y / 2;
    float centerDis = BUTTON_SIZE_Y + BUTTON_DISTANCE;

    this->playButton = std::make_unique<Button>(sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Play");
    this->playButton->setPosition(System.window.getSize().x / 2, firstPos);

    this->choseCharacterButton = std::make_unique<Button>(sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Chose Character");
    this->choseCharacterButton->setPosition(System.window.getSize().x / 2, firstPos + centerDis);

    this->tutorialButton = std::make_unique<Button>(sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), "Tutorial");
    this->tutorialButton->setPosition(System.window.getSize().x / 2, firstPos + 2 * centerDis);
}

void MenuState::update(float deltaTime)
{
    this->playButton->update(deltaTime);

    this->choseCharacterButton->update(deltaTime);

    this->tutorialButton->update(deltaTime);

    if (this->playButton->isClick())
    {
        System.machine.addState(StateRef(std::make_unique<ChoseLevelState>()));
    }
    else if (this->choseCharacterButton->isClick())
    {
        System.machine.addState(StateRef(std::make_unique<ChoseCharacterState>()));
    }
    else if (this->tutorialButton->isClick())
    {
        System.machine.addState(StateRef(std::make_unique<TutorialState>()));
    }
}

void MenuState::draw()
{
    System.window.clear(sf::Color::White);

    this->playButton->draw();
    this->choseCharacterButton->draw();
    this->tutorialButton->draw();

    System.window.display();
}