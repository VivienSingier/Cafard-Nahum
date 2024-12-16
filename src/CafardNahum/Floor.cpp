#include "pch.h"
#include "Floor.h"

Floor::Floor(sf::Texture, sf::Vector2f position, sf::Vector2f scale) :
	StaticObject(texture, position, scale, true)
{
	collisionRect = new ColliderRect(position.x, position.y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

	sprite.setOrigin(sf::Vector2f(0.f, sprite.getGlobalBounds().height));
}
