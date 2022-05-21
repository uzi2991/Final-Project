#include "MenuState/ChoseLevelState.hpp"
#include "GameState/GameState.hpp"
#include "Engine/SharedContext.hpp"

#define BUTTON_SIZE_X 50
#define BUTTON_SIZE_Y 50
#define BUTTON_DISTANCE 25
#define NUM_BUTTONS 3

void ChoseLevelState::init()
{
    float totalXWidth = NUM_BUTTONS * BUTTON_SIZE_X + (NUM_BUTTONS - 1) * BUTTON_DISTANCE;
    float firstPos = System.window.getSize().x / 2 - totalXWidth / 2 + BUTTON_SIZE_X / 2;
    float centerDis = BUTTON_SIZE_X + BUTTON_DISTANCE;
    for (int i = 0; i < NUM_BUTTONS; ++i)
    {
        std::unique_ptr<Button> newButton = std::make_unique<Button>(sf::Vector2f(BUTTON_SIZE_X, BUTTON_SIZE_Y), std::to_string(i + 1));
        newButton->setPosition(firstPos + i * centerDis, System.window.getSize().y / 2);
        this->levelButton.push_back(std::move(newButton));
    }
}

void ChoseLevelState::update(float deltaTime)
{
    for (const auto &button : this->levelButton)
    {
        button->update(deltaTime);
    }

    for (const auto &button : this->levelButton)
    {
        if (button->isClick())
        {
            System.machine.addState(StateRef(std::make_unique<GameState>(button->getContent())));
            break;
        }
    }
}

void ChoseLevelState::draw()
{
    System.window.clear(sf::Color::White);

    for (const auto &button : this->levelButton)
    {
        button->draw();
    }

    System.window.display();
}