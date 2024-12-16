#pragma once
#include "StaticObject.h"

class HalfWall : public StaticObject
{
public:
	HalfWall(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale);
};

