#include "pch.h"
#include "Player.h"

Player::Player(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f cSpeed) :
	Entity::Entity(path, textureRect, position, scale),
	Movable::Movable(cSpeed),
	Alive::Alive(cHealth),
	ColliderSphere::ColliderSphere()
{

}