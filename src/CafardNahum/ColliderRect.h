#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class ColliderSphere;

class ColliderRect
{
public:
	sf::FloatRect rect;

	ColliderRect(float x, float y, float width, float height);
};

