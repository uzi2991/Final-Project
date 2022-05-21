#pragma once

#include "Engine/Component.hpp"
#include "Utility/Animation.hpp"
#include <map>

class C_Animation: public Component
{
public:
    C_Animation() {}

    void lateUpdate(float deltaTime) override final;

    void draw() override final;

    void addAnimation(const std::string& name, const Animation& animation);

    void switchAnimation(const std::string& name);

private:
    std::map<std::string, Animation> animations;
    
    std::string currentAnimation;
};


