#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>

namespace eng
{
	void Engine::init(ContentManager& manager)
	{
		this->manager = &manager;
	}

	void Engine::cleanUp()
	{

	}

	void Engine::changeState(IGameState* state)
	{
		if(!gameStates.empty()) gameStates.top()->cleanup();
		gameStates.push(state);
		state->init();
	}

	void Engine::pushState(IGameState* state)
	{
		if (!gameStates.empty()) gameStates.top()->cleanup();
		gameStates.push(state);
		state->init();
	}

	void Engine::popState()
	{
		if (!gameStates.empty()) gameStates.top()->cleanup();
		gameStates.pop();
	}

	void Engine::handleEvents()
	{
	}

	void Engine::update(sf::RenderWindow& window, sf::Time elapsed)
	{
		updater.update(*this, window, elapsed);
		gameStates.top()->update(*this, window, elapsed);
	}

	void Engine::draw(sf::RenderWindow& window)
	{
		updater.draw(window);
		gameStates.top()->draw(window);
	}
	void Engine::closeGame()
	{
		gameIsRunning = false;
	}

	bool Engine::isGameRunning() const
	{
		return gameIsRunning;
	}

	void Engine::addToUpdater(GameObject* gameObject)
	{
		updater.addGameObject(gameObject);
	}

	void Engine::addToUpdater(IUpdatable* updatable)
	{
		updater.addUpdatable(updatable);
	}
}
