#pragma once
#include <SFML/Graphics/Rect.hpp>

class Frame
{
public:
	Frame(sf::IntRect rect, float duration);
	~Frame();
};

