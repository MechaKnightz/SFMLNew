#pragma once

namespace eng {
	class Engine;
}

namespace sf {
	class Time;
	class RenderWindow;
}

class IUpdatable
{
protected:
	~IUpdatable() = default;
public:
	virtual void update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed) = 0;
};
