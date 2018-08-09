#pragma once
#include "Entity.h"
#include <SFML/Graphics/Drawable.hpp>

class GameObject : public Entity, public sf::Drawable
{
public:
	int layer = 0;
	bool isStatic = true;

	bool operator() (const GameObject& struct1, const GameObject& struct2) const
	{
		return (struct1.y < struct2.y);
	}

	float getY() const { return y; }
	float getX() const { return x; }
};
