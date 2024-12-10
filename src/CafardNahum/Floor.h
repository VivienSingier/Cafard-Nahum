#pragma once
#include "StaticObject.h"

class Floor : public StaticObject
{
public:
	Floor(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale);
};

