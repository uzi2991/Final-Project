#pragma once

#include "Engine/State.hpp"
#include "Utility/Button.hpp"

class GameOverState: public State
{
public:
    GameOverState(bool win): win(win) {}

    void init() override final;

    void update(float deltaTime) override final;

    void draw() override final;

private:
    std::unique_ptr<Button> backToMenuButton;
    
    sf::Text gameOverText;

    bool win;
};
