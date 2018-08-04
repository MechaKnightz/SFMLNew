#pragma once
#include "IGameState.h"
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class MainMenu : public IGameState
{
public:

	static MainMenu& instance(ContentManager& manager, eng::Engine& engine)
	{
		static MainMenu instance(manager, engine);
		return instance;
	}

	void init() override;
	void cleanup() override;

	void pause() override;
	void resume() override;

	void handleEvents() override;
	void update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed) override;
	void draw(sf::RenderWindow& window) override;

	MainMenu(MainMenu const&) = delete;
	void operator=(MainMenu const&) = delete;
private:
	MainMenu(ContentManager& manager, eng::Engine& engine) : IGameState(manager, engine) {}

	ContentManager* manager;
	Sprite sprite;
};

