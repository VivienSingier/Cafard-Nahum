#pragma once
#include "StaticObject.h"

class ColliderRect;

class Wall : public StaticObject
{

public:
	Wall(sf::Texture texture, sf::Vector2f position, sf::Vector2f scale);
};

