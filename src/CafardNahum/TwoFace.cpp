#include "pch.h"
#include "TwoFace.h"

TwoFace::TwoFace(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth) :
	Boss::Boss(path, textureRect, position, scale, speed, cHealth)
{

}