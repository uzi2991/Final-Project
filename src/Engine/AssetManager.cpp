#include "Engine/AssetManager.hpp"
#include <iostream>

void AssetManager::loadTexture(const std::string &name, const std::string &filePath)
{
    if (this->textures.find(name) != this->textures.end())
    {
        return;
    }

    sf::Texture tex;
    if (tex.loadFromFile(filePath))
    {
        this->textures[name] = tex;
    }
    else
    {
        throw "Cannot load Texture!";
    }
}

void AssetManager::unLoadTexture(const std::string &name)
{
    this->textures.erase(name);
}

sf::Texture &AssetManager::getTexture(const std::string &name)
{
    return this->textures.at(name);
}

void AssetManager::loadFont(const std::string &name, const std::string &filePath)
{
    if (this->fonts.find(name) != this->fonts.end())
    {
        return;
    }

    sf::Font font;
    if (font.loadFromFile(filePath))
    {
        this->fonts[name] = font;
    }
    else
    {
        throw "Cannot load Font!";
    }
}

void AssetManager::unLoadFont(const std::string &name)
{
    this->fonts.erase(name);
}

sf::Font &AssetManager::getFont(const std::string &name)
{
    return this->fonts.at(name);
}

void AssetManager::loadSoundBuffer(const std::string &name, const std::string &filePath)
{
    if (this->sounds.find(name) != this->sounds.end())
    {
        return;
    }

    sf::SoundBuffer sound;
    if (sound.loadFromFile(filePath))
    {
        this->sounds[name] = sound;
    }
    else
    {
        throw "Cannot load Sound!";
    }
}

void AssetManager::unLoadSoundBuffer(const std::string &name)
{
    this->sounds.erase(name);
}

sf::SoundBuffer &AssetManager::getSoundBuffer(const std::string &name)
{
    return this->sounds.at(name);
}
