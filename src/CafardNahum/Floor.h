#pragma once
#include "StaticObject.h"

class Floor : public StaticObject
{
public:
	Floor(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale);
};

