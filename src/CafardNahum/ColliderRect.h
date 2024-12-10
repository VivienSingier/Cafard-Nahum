#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class ColliderSphere;

class ColliderRect
{
	std::vector <sf::FloatRect*> rects;

public:
	bool GetCollisionWithRect(ColliderRect* object);
	bool GetCollisionWithSphere(ColliderSphere* object);
};

