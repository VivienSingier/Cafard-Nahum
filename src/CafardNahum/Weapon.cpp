#include "pch.h"
#include "Weapon.h"

Weapon::Weapon(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed) :
	Entity(path, textureRect, position, scale),
	Movable(speed)
{

}

