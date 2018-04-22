#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "Engine.h"
#include <iostream>
#include <chrono>

namespace eng
{
	Engine::Engine(sf::RenderWindow* win)
	{
		window = win;
	}

	int Engine::run()
	{
		std::cout << "Starting..";
		gameIsRunning = true;
		startingTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();;
		double next_game_tick = getTickCount();
		int loops;
		float interpolation;

		while (gameIsRunning) {

			loops = 0;
			long tempvar = getTickCount();
			while ( tempvar > next_game_tick && loops < MAX_FRAMESKIP) {
				update();

				next_game_tick += SKIP_TICKS;
				loops++;
			}

			interpolation = float(getTickCount() + SKIP_TICKS - next_game_tick)
				/ float(SKIP_TICKS);
			render(interpolation);
		}
		return -1;
	}

	long Engine::getTickCount()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - startingTime;
	}

	sf::CircleShape* shape;
	void Engine::loadContent()
	{
		shape = new sf::CircleShape(200.f);
		shape->setFillColor(sf::Color::Green);
	}

	int counter = 0;
	void Engine::update()
	{
		std::cout << "updating: " << counter <<"\n";
		counter++;
	}

	void Engine::render(float interp)
	{
		window->clear();
		window->draw(*shape);
		window->display();
	}
}