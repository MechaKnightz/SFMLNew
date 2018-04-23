#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
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
		std::cout << "Loading Content...";
		loadContent();
		std::cout << "Starting...";
		startingTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();;
		double next_game_tick = static_cast<double>(getTickCount());

		while (window->isOpen()) {

			int loops = 0;
			int64_t tempvar = getTickCount();
			while ( tempvar > next_game_tick && loops < MAX_FRAMESKIP) {
				update();

				next_game_tick += SKIP_TICKS;
				loops++;
			}

			float interpolation = float(getTickCount() + SKIP_TICKS - next_game_tick)
				/ float(SKIP_TICKS);
			render(interpolation);
		}
		return -1;
	}

	int64_t Engine::getTickCount()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - startingTime;
	}

	sf::VertexArray triangle(sf::Triangles, 3);

	void Engine::loadContent()
	{
		triangle[0].position = sf::Vector2f(100, 300);
		triangle[1].position = sf::Vector2f(300, 300);
		triangle[2].position = sf::Vector2f(200, 100);

		triangle[0].color = sf::Color::Blue;
		triangle[1].color = sf::Color::Blue;
		triangle[2].color = sf::Color::Blue;
	}

	int counter = 0;
	void Engine::update()
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		std::cout << "updating: " << counter <<"\n";
		counter++;
	}

	void Engine::render(float interp)
	{
		window->clear();
		window->draw(triangle);
		window->display();
	}
}