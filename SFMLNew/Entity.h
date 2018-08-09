#pragma once
#include "IUpdatable.h"
#include <SFML/System/Time.hpp>

class Entity : public IUpdatable
{
public:
	void update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed) override { }
protected:
	~Entity() = default;
	float x, y, rot, xScale, yScale;
};
