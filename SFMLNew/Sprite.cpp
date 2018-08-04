#include "Sprite.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

Sprite::Sprite(sf::Texture& texture)
{
	setTexture(texture);
}

Sprite::Sprite()
{
}

void Sprite::setPos(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Sprite::update()
{
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (texture)
	{
		states.transform *= getTransform();
		states.texture = texture;
		target.draw(vertices, 4, sf::TriangleStrip, states);
	}
}

void Sprite::setTexture(sf::Texture& texture)
{
	this->texture = &texture;
	rect = sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y);
	updateCoords();
	updateTexCoords();
}

void Sprite::updateCoords()
{
	sf::FloatRect bounds = getLocalBounds();

	vertices[0].position = sf::Vector2f(0, 0);
	vertices[1].position = sf::Vector2f(0, bounds.height);
	vertices[2].position = sf::Vector2f(bounds.width, 0);
	vertices[3].position = sf::Vector2f(bounds.width, bounds.height);
}

void Sprite::updateTexCoords()
{
	float left = static_cast<float>(rect.left);
	float right = left + rect.width;
	float top = static_cast<float>(rect.top);
	float bottom = top + rect.height;

	vertices[0].texCoords = sf::Vector2f(left, top);
	vertices[1].texCoords = sf::Vector2f(left, bottom);
	vertices[2].texCoords = sf::Vector2f(right, top);
	vertices[3].texCoords = sf::Vector2f(right, bottom);
}

sf::FloatRect Sprite::getLocalBounds() const
{
	float width = static_cast<float>(std::abs(rect.width));
	float height = static_cast<float>(std::abs(rect.height));

	return sf::FloatRect(0.f, 0.f, width, height);
}