#include "Updater.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

void Updater::addDrawable(sf::Drawable* drawable)
{
	drawables.push_back(drawable);
}

void Updater::addUpdatable(Updatable* updatable)
{
	updatables.push_back(updatable);
}

void Updater::draw(sf::RenderWindow& window)
{
	for (auto i = 0; i < drawables.size(); i++)
	{
		if (!drawables[i])
		{
			drawables.erase(drawables.begin() + i);
			i--;
		}
		window.draw(*drawables[i]);
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
