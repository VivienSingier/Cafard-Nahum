#include "pch.h"
#include "Boss.h"

Boss::Boss(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f speed) :
	Enemy::Enemy(path, textureRect, position, scale, cHealth, speed )
{

}