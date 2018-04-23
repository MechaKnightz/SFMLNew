#pragma once
#include <SFML/Graphics.hpp>

namespace eng
{
	class Engine
	{
	public:
		Engine::Engine(sf::RenderWindow* win);
		int Engine::run();
	private:
		sf::RenderWindow* window;
		bool gameIsRunning;
		int64_t startingTime;

		const int TICKS_PER_SECOND = 100;
		const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
		const int MAX_FRAMESKIP = 5;

		int64_t getTickCount();
		void loadContent();
		void render(float interp);
		void update();
	};
}