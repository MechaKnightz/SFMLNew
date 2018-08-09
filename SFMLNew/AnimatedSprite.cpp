#include "stdafx.h"
#include "AnimatedSprite.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <array>

AnimatedSprite::AnimatedSprite()
{
}


AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed)
{
	animPlayer.update(engine, window, elapsed);
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Texture* texture = animPlayer.getTexture();
	std::array<sf::Vertex, 4> vertexArray = animPlayer.getSourceRect();

	if (texture)
	{
		states.transform *= getTransform();
		states.texture = texture;
		target.draw(&vertexArray[0], 4, sf::TriangleStrip, states);
	}
}

void AnimatedSprite::setAnimation(Animation* animation)
{
	animPlayer.setAnimation(animation);
}
