#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include "IUpdatable.h"
#include <vector>


namespace eng {
	class Engine;
}

class Updater : public Updatable
{
public:
	void addDrawable(sf::Drawable* drawable);
	void addUpdatable(Updatable* updatable);

	void draw(sf::RenderWindow& window);
	void update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed) override;
private:
	std::vector<sf::Drawable*> drawables;
	std::vector<Updatable*> updatables;
};
