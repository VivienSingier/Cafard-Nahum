#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(sf::Texture texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth) :
	Entity::Entity(texture, position, scale),
	Movable::Movable(speed),
	Alive::Alive(cHealth)
{

}