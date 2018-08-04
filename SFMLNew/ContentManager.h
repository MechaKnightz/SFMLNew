#pragma once
#include <string>
#include <map>
#include <SFML/Graphics/Texture.hpp>

class ContentManager
{
public:
	ContentManager(std::string baseDir);
	~ContentManager();

	template <typename T>
	T& loadContent(std::string contentName);

	void unloadTextures()
	{
		loadedTextures.clear();
	}

private:
	std::string baseDir;
	std::map<std::string, std::string> matcher;
	std::map<std::string, sf::Texture> loadedTextures;
};

template <typename T>
T& ContentManager::loadContent(std::string contentName)
{
	if (std::is_same<T, sf::Texture>::value)
	{
		sf::Texture texture;
		if (loadedTextures.find(contentName) == loadedTextures.end())
		{
			texture.loadFromFile(matcher.at(contentName));
			loadedTextures.insert(make_pair(contentName, texture));
		}
		return loadedTextures.at(contentName);
	}
	else throw "Unsupported format.";
}