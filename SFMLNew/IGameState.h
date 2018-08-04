#pragma once
class ContentManager;

namespace eng {
	class Engine;
}

namespace sf {
	class Time;
	class RenderWindow;
}

class IGameState
{
public:
	virtual void init() = 0;
	virtual void cleanup() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleEvents() = 0;
	virtual void update(eng::Engine&engine, sf::RenderWindow& window, sf::Time elapsed) = 0;
	virtual void draw(sf::RenderWindow&) = 0;

protected:
	IGameState(ContentManager& manager, eng::Engine& eng)
	{
		contentManager = &manager;
		engine = &eng;
	}

	ContentManager* contentManager;
	eng::Engine* engine;
};
