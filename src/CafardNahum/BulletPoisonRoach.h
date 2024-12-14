#pragma once
#include "Bullet.h"

class BulletPoisonRoach : public Bullet
{
public:
	int damage;

	BulletPoisonRoach(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed);
};





