#pragma once
#include <string>
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include "Animation.h"

class ContentManager
{
public:
	ContentManager(std::string baseDir);
	~ContentManager();

	sf::Texture& loadTexture(std::string contentName);
	Animation& loadAnimation(std::string contentName);

	void unloadTextures()
	{
		loadedTextures.clear();
	}

private:
	std::string baseDir;
	std::map<std::string, std::string> matcher;
	std::map<std::string, sf::Texture> loadedTextures;
	std::map<std::string, Animation> loadedAnimations;
};