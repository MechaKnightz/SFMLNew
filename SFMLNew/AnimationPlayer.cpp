#include "stdafx.h"
#include "AnimationPlayer.h"
#include <SFML/System/Time.hpp>


AnimationPlayer::AnimationPlayer()
{
	currentAnimation = nullptr;
	currentFrameIndex = 0;
	currentMilliseconds = 0;
}


AnimationPlayer::~AnimationPlayer()
{
}

sf::Texture* AnimationPlayer::getTexture() const
{
	return currentAnimation->texture;
}

std::array<sf::Vertex, 4> AnimationPlayer::getSourceRect() const
{
	return currentVertices;
}


void AnimationPlayer::update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed)
{
	if (currentAnimation == nullptr) return;
	currentMilliseconds += elapsed.asMilliseconds();
	if (currentMilliseconds > currentAnimation->frames[currentFrameIndex].getDuration())
	{
		currentMilliseconds -= currentAnimation->frames[currentFrameIndex].getDuration();
		if (currentFrameIndex == currentAnimation->frames.size() - 1)
			currentFrameIndex = 0;
		else
			currentFrameIndex++;
		setVertices(currentAnimation->frames[currentFrameIndex].getSourceRect(), currentAnimation->frames[currentFrameIndex].getSizeRect(), currentVertices);
	}
}

void AnimationPlayer::setAnimation(Animation* animation)
{
	currentAnimation = animation;
	currentFrameIndex = 0;
	currentMilliseconds = 0;
	setVertices(currentAnimation->frames[currentFrameIndex].getSourceRect(), currentAnimation->frames[currentFrameIndex].getSizeRect(), currentVertices);
}

void AnimationPlayer::setVertices(sf::IntRect& textureRect, sf::IntRect& sizeRect, std::array<sf::Vertex, 4>& vertexArray)
{
	vertexArray[0].texCoords = sf::Vector2f(textureRect.left, textureRect.top);
	vertexArray[1].texCoords = sf::Vector2f(textureRect.left, textureRect.top + textureRect.height);
	vertexArray[2].texCoords = sf::Vector2f(textureRect.left + textureRect.width, textureRect.top);
	vertexArray[3].texCoords = sf::Vector2f(textureRect.left + textureRect.width, textureRect.top + textureRect.height);

	vertexArray[0].position = sf::Vector2f(sizeRect.left, sizeRect.top);
	vertexArray[1].position = sf::Vector2f(sizeRect.left, sizeRect.top + sizeRect.height);
	vertexArray[2].position = sf::Vector2f(sizeRect.left + sizeRect.width, sizeRect.top);
	vertexArray[3].position = sf::Vector2f(sizeRect.left + sizeRect.width, sizeRect.top + sizeRect.height);
}