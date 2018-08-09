#pragma once

#include <SFML/Graphics.hpp>
#include "IGameState.h"
#include <stack>
#include "Updater.h"

class IGameState;

namespace eng
{
	class Engine
	{
	public:
		Engine::Engine(ContentManager& manager)
		{
			init(manager);
		}

		void init(ContentManager& manager);
		void cleanUp();

		void changeState(IGameState* state);
		void pushState(IGameState* state);
		void popState();

		void handleEvents();
		void update(sf::RenderWindow& window, sf::Time elapsed);
		void draw(sf::RenderWindow& window);

		void closeGame();
		bool isGameRunning() const;

		void addToUpdater(GameObject* gameObject);
		void addToUpdater(IUpdatable* updatable);
	private:
		std::stack<IGameState*> gameStates;
		ContentManager* manager;
		Updater updater;
		bool gameIsRunning = true;
	};
}
