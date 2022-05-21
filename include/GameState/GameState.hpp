#include "Engine/State.hpp"
#include "GameState/Level.hpp"
#include "GameState/GameHUD.hpp"
#include "GameState/Background.hpp"
#include <string>
#include "SFML/Audio.hpp"

class GameState : public State
{
public:
    GameState(const std::string &levelNum) : levelNum(levelNum) {}

    void init() override final;

    void destroy() override final;

    void handleInput() override final;

    void fixedUpdate(float deltaTime) override final;

    void update(float deltaTime) override final;

    void lateUpdate(float deltaTime) override final;

    void draw() override final;

private:
    std::string levelNum;

    std::unique_ptr<Level> level;

    std::unique_ptr<GameHUD> hud;

    std::unique_ptr<Background> background;

    sf::Sound backgroundMusic;
};