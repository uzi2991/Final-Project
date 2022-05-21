#pragma once

#include <map>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

/*
    class to manage textures, fonts, sounds
*/
class AssetManager
{
public:
    AssetManager() {}

    void loadTexture(const std::string &name, const std::string &filePath);

    void unLoadTexture(const std::string& name);

    sf::Texture &getTexture(const std::string &name);

    void loadSoundBuffer(const std::string& name, const std::string& filePath);

    void unLoadSoundBuffer(const std::string& name);

    sf::SoundBuffer& getSoundBuffer(const std::string& name);

    void loadFont(const std::string &name, const std::string &filePath);

    void unLoadFont(const std::string& name);

    sf::Font &getFont(const std::string &name);

private:
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Font> fonts;
    std::map<std::string, sf::SoundBuffer> sounds;
};