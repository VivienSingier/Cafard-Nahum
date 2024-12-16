#include "pch.h"
#include "Boss.h"

Boss::Boss(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth) :
	Enemy::Enemy(texture, position, scale, speed, cHealth)
{

}