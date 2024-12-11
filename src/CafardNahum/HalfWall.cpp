#include "pch.h"
#include "HalfWall.h"

HalfWall::HalfWall(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale) :
	StaticObject(path, textureRect, position, scale, false)
{
	sf::FloatRect* newRect = new sf::Rect <float>(position, sf::Vector2f(textureRect.width, textureRect.height/2));
	rects.push_back(newRect);
}