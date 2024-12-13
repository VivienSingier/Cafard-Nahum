#include "pch.h"
#include "Wall.h"

Wall::Wall(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale) :
	StaticObject(path, textureRect, position, scale, false)
{
	collisionRect = new ColliderRect(position.x, position.y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
	
	sprite.setOrigin(sf::Vector2f(0.f, sprite.getGlobalBounds().height));
}