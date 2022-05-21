#pragma once

#include "Engine/State.hpp"
#include "SFML/Graphics.hpp"
#include "Utility/Button.hpp"
#include "Utility/Animation.hpp"
#include <vector>
#include "json/json.h"

class ChoseCharacterState : public State
{
public:
    void init() override final;

    void update(float deltaTime) override final;

    void draw() override final;

private:
    void read();
    void save();

private:
    std::vector<sf::Text> characterNames;
    std::vector<Animation> characterAnims;

    Json::Value settings;

    int currentCharacter;

    std::unique_ptr<Button> backButton;
    std::unique_ptr<Button> nextButton;
    std::unique_ptr<Button> prevButton;
};