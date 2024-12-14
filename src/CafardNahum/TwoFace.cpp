#include "pch.h"
#include "TwoFace.h"

TwoFace::TwoFace(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f speed) :
	Boss::Boss(path, textureRect, position, scale, cHealth, speed )
{

}