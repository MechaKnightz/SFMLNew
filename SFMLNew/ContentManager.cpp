#include "stdafx.h"
#include "ContentManager.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <fstream>

ContentManager::ContentManager(std::string baseDir)
{
	this->baseDir = baseDir;
	//content.insert(std::make_pair("test", sf::Texture()));

	std::ifstream managerFile;
	managerFile.open(baseDir + "Content.ctn");
	if (managerFile.is_open())
	{
		std::string key;
		std::string value;
		while (managerFile.peek() != EOF)
		{
			getline(managerFile, key);
			getline(managerFile, value);

			matcher.insert(make_pair(key, value));
		}
	}
}

ContentManager::~ContentManager()
{
}

sf::Texture& ContentManager::loadTexture(std::string contentName)
{
	sf::Texture texture;
	if (loadedTextures.find(contentName) == loadedTextures.end())
	{
		texture.loadFromFile(matcher.at(contentName));
		loadedTextures.insert(make_pair(contentName, texture));
	}
	return loadedTextures.at(contentName);
}

Animation& ContentManager::loadAnimation(std::string contentName)
{
	Animation animation;
	if (loadedAnimations.find(contentName) == loadedAnimations.end())
	{
		animation.loadFromFile(matcher.at(contentName), this);
		loadedAnimations.insert(make_pair(contentName, animation));
	}
	return loadedAnimations.at(contentName);
}