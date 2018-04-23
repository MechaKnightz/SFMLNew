#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

	eng::Engine eng(&window);
	eng.run();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}