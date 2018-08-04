#pragma once
#include "IGameState.h"
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class TestState : public IGameState
{
public:

	static TestState& instance(ContentManager& manager, eng::Engine& engine)
	{
		static TestState instance(manager, engine);
		return instance;
	}

	void init() override;
	void cleanup() override;

	void pause() override;
	void resume() override;

	void handleEvents() override;
	void update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed) override;
	void draw(sf::RenderWindow& window) override;

	TestState(TestState const&) = delete;
	void operator=(TestState const&) = delete;
private:
	TestState(ContentManager& manager, eng::Engine& engine) : IGameState(manager, engine) {}

	Sprite sprite;
};
