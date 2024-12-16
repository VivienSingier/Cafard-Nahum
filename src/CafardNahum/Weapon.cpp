#include "pch.h"
#include "Weapon.h"

Weapon::Weapon(sf::Texture textture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed) :
	Entity(texture, position, scale),
	Movable(speed)
{

}

void Weapon::Move(float x, float y)
{
	move(x, y);
}

