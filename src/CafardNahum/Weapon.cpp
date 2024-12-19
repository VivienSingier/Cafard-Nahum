#include "pch.h"
#include "Weapon.h"

Weapon::Weapon(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, float cDelay) :
	Entity(texture, position, scale),
	Movable(speed)
{
	delay = cDelay;
}

void Weapon::Move(float x, float y)
{
	move(x, y);
}

float Weapon::getDelay()
{
	return delay;
}
