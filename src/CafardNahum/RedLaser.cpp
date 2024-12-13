#include "pch.h"
#include "RedLaser.h"

RedLaser::RedLaser(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed) :
	Bullet::Bullet(path, textureRect, position, scale, cSpeed)
{
	damage = 2;
}

