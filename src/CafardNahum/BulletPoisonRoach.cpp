#include "pch.h"
#include "BulletPoisonRoach.h"

BulletPoisonRoach::BulletPoisonRoach(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed) :
	Bullet::Bullet(path, textureRect, position, scale, cSpeed)
{
	damage = 2;
}
