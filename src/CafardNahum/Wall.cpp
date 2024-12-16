#include "pch.h"
#include "Wall.h"

Wall::Wall(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale) :
	StaticObject(texture, position, scale, false)
{
	collisionRect = new ColliderRect(position.x, position.y + 16, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height / 2);
	
	sprite.setOrigin(sf::Vector2f(0.f, sprite.getGlobalBounds().height));
}