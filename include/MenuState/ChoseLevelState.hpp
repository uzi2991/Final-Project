#pragma once

#include "Engine/State.hpp"
#include "Utility/Button.hpp"

class ChoseLevelState: public State
{
public:
    ChoseLevelState() {}

    void init() override final;

    void update(float deltaTime) override final;

    void draw() override final;

private:
    std::vector<std::unique_ptr<Button>> levelButton;
};