#include "Updater.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameObject.h"

struct Comparator
{
	bool operator() (const GameObject* first, const GameObject* second) const
	{
		return first->getY() < second->getY();
	}
};

void Updater::addGameObject(GameObject* gameObject)
{
	if(gameObject->isStatic)
	{
		staticDrawables[gameObject->layer].push_back(gameObject);
	}
	else
	{
		drawables[gameObject->layer].push_back(gameObject);
	}
	updatables.push_back(gameObject);
}

void Updater::addUpdatable(IUpdatable* updatable)
{
	updatables.push_back(updatable);
}

void Updater::draw(sf::RenderWindow& window)
{
	for (auto i = 0; i < LAYERCOUNT; i++)
	{
		auto currentLayer = staticDrawables[i];
		for (auto j = 0; j < currentLayer.size(); j++)
		{
			const auto currentDrawable = currentLayer[j];
			
			if (!currentDrawable)
			{
				currentLayer.erase(currentLayer.begin() + j);
				j--;
			}
			else
			{
				window.draw(*currentDrawable);
			}
		}

		currentLayer = drawables[i];
		sort(currentLayer.begin(), currentLayer.end(), Comparator());
		for (auto j = 0; j < currentLayer.size(); j++)
		{
			const auto currentDrawable = currentLayer[j];

			if (!currentDrawable)
			{
				currentLayer.erase(currentLayer.begin() + j);
				j--;
			}
			else
			{
				window.draw(*currentDrawable);
			}
		}
	}
}

void Updater::update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed)
{
	for (auto i = 0; i < updatables.size(); i++)
	{
		if (!updatables[i])
		{
			updatables.erase(updatables.begin() + i);
			i--;
		}
		updatables[i]->update(engine, window, elapsed);
	}
}
