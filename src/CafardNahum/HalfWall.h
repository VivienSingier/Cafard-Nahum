#pragma once
#include "StaticObject.h"

class HalfWall : public StaticObject
{
public:
	HalfWall(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale);
};

