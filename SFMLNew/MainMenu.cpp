#include "stdafx.h"
#include "MainMenu.h"
#include "Engine.h"
#include "TestState.h"
#include "ContentManager.h"
#include "AnimatedSprite.h"

void MainMenu::init()
{
	//sprite.setTexture(contentManager->loadTexture("texture1"));
	//engine->addToUpdater(&sprite);
	animatedSprite.setAnimation(&contentManager->loadAnimation("testAnimation"));
	engine->addToUpdater(&animatedSprite);
}

void MainMenu::cleanup()
{
	manager->unloadTextures();
}

void MainMenu::pause()
{
}

void MainMenu::resume()
{
}

void MainMenu::handleEvents()
{
}

void MainMenu::update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		engine.closeGame();
	}

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sprite.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	}
}

void MainMenu::draw(sf::RenderWindow& window)
{
}
