#include "pch.h"
#include "HalfWall.h"

HalfWall::HalfWall(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale) :
	StaticObject(texture, position, scale, false)
{
	collisionRect = new ColliderRect(position.x, position.y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

	sprite.setOrigin(sf::Vector2f(0.f, sprite.getGlobalBounds().height));
}