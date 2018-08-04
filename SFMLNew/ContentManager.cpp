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
	managerFile.open(baseDir + "Content.txt");
	if(managerFile.is_open())
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

