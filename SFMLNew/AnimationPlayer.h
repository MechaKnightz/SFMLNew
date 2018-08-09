#pragma once
#include "Animation.h"
#include <SFML/Graphics/Vertex.hpp>
#include <array>

namespace eng {
	class Engine;
}

namespace sf {
	class Time;
	class RenderWindow;
	class Texture;
}

class AnimationPlayer
{
public:
	AnimationPlayer();
	~AnimationPlayer();

	sf::Texture* getTexture() const;

	std::array<sf::Vertex, 4> getSourceRect() const;

	void update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed);

	void setAnimation(Animation* animation);
private:
	Animation* currentAnimation;
	unsigned int currentFrameIndex;
	unsigned int currentMilliseconds;
	std::array<sf::Vertex, 4> currentVertices;
	static void setVertices(sf::IntRect& rect, sf::IntRect& sizeRect, std::array<sf::Vertex, 4>& array);
};

