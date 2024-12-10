#include "pch.h"
#include "PoisonRoach.h"

PoisonRoach::PoisonRoach(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth) :
	Enemy(path, textureRect, position, scale, speed, cHealth)
{

}
