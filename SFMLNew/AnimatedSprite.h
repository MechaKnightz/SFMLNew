#pragma once
#include "Sprite.h"
#include "AnimationPlayer.h"

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite();
	~AnimatedSprite();

	void update(eng::Engine& engine, sf::RenderWindow& window, sf::Time elapsed) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setAnimation(Animation* animation);
private:
	AnimationPlayer animPlayer;
};

