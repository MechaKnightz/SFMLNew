#include "stdafx.h"
#include "AnimatedSprite.h"
#include <SFML/Graphics/RenderTarget.hpp>

AnimatedSprite::AnimatedSprite()
{
}


AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::update()
{
	animPlayer.update();
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Texture* texture = animPlayer.getCurrentTexture();

	if (texture)
	{
		states.transform *= getTransform();
		states.texture = texture;
		target.draw(vertices, 4, sf::TriangleStrip, states);
	}
}
