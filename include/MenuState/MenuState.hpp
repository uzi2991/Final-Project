#pragma once

#include "Engine/State.hpp"
#include "Utility/Button.hpp"

class MenuState: public State
{
public:
    MenuState() {}

    void init() override final;

    void update(float deltaTime) override final;

    void draw() override final;

private:

    std::unique_ptr<Button> playButton;

    std::unique_ptr<Button> choseCharacterButton;

    std::unique_ptr<Button> tutorialButton;

};