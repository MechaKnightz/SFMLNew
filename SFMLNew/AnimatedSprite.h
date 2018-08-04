#pragma once
#include "Sprite.h"
#include "AnimationPlayer.h"

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite();
	~AnimatedSprite();

	void update() override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	AnimationPlayer animPlayer;
};

