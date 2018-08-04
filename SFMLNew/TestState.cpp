#include "stdafx.h"
#include "TestState.h"
#include "Engine.h"
#include "ContentManager.h"

void TestState::init()
{
	sprite = Sprite(contentManager->loadContent<sf::Texture>("texture2"));
}

void TestState::cleanup()
{
	contentManager->unloadTextures();
}

void TestState::pause()
{
}

void TestState::resume()
{
}

void TestState::handleEvents()
{
}

void TestState::update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		engine.popState();
	}
}

void TestState::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
