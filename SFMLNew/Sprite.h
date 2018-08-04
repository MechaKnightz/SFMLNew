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

	void update() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
protected:
	void updateCoords();
	void updateTexCoords();
	sf::FloatRect getLocalBounds() const;

	sf::Vertex vertices[4];
	sf::IntRect rect;
private:
	sf::Texture* texture;
};
