#include "pch.h"
#include "Boss.h"

Boss::Boss(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth) :
	Enemy::Enemy(path, textureRect, position, scale, speed, cHealth)
{

}