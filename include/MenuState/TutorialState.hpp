#pragma once

#include "Engine/State.hpp"
#include "Utility/Button.hpp"

class TutorialState: public State
{
public:
    void init() override final;

    void update(float deltaTime) override final;

    void draw() override final;

private:
    std::unique_ptr<Button> backButton;
    sf::Text tutorialText;
};