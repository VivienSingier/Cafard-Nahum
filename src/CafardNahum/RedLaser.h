#pragma once
#include "Bullet.h"

class RedLaser : public Bullet
{
public:
	int damage;

	RedLaser(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed);
};

