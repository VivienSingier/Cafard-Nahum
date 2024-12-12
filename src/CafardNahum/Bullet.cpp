#include "pch.h"
#include "Bullet.h"

Bullet::Bullet(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed) : 
	Entity::Entity(path, textureRect, position, scale),
	Movable::Movable(cSpeed),
	ColliderSphere::ColliderSphere()
{

}

void Bullet::Update(float deltatime)
{
	Move(deltatime);
}

