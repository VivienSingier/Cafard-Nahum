#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth) :
	Entity::Entity(path, textureRect, position, scale),
	Movable::Movable(speed),
	Alive::Alive(cHealth),
	ColliderSphere::ColliderSphere(0,0,0)
{

}