#pragma once
#include "IUpdatable.h"
#include <vector>


class GameObject;

const int LAYERCOUNT = 4;

namespace eng {
	class Engine;
}

class Updater
{
public:
	void addGameObject(GameObject* gameObject);
	void addUpdatable(IUpdatable* updatable);

	void draw(sf::RenderWindow& window);
	void update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed);
private:
	std::vector<GameObject*> staticDrawables[LAYERCOUNT];
	std::vector<GameObject*> drawables[LAYERCOUNT];

	std::vector<IUpdatable*> updatables;
};
