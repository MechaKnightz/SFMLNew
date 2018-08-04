#pragma once
#include <SFML/Graphics/Texture.hpp>

class AnimationPlayer
{
public:
	AnimationPlayer();
	~AnimationPlayer();

	sf::Texture* getCurrentTexture() const;
	void update();
};

