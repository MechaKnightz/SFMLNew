#pragma once
#include "GameObject.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Sprite : public GameObject, public sf::Transformable
{
public:
	Sprite(sf::Texture& texture);
	Sprite();

	void setPos(float x, float y);
	void setTexture(sf::Texture& texture);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	void updateCoords();
	void updateTexCoords();
	sf::FloatRect getLocalBounds() const;

private:
	sf::IntRect rect;
	sf::Texture* texture;
	sf::Vertex vertices[4];
};
