#pragma once
#include "StaticObject.h"

class Wall : public StaticObject
{
public:
	Wall(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale);
};

