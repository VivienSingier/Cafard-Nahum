#include "pch.h"
#include "Bullet.h"
#include "GameManager.h"

Bullet::Bullet(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed) : 
	Entity::Entity(path, textureRect, position, scale),
	Movable::Movable(cSpeed),
	ColliderSphere::ColliderSphere()
{

}


