#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class ColliderSphere;

class ColliderRect
{
protected:
	std::vector <sf::FloatRect*> rects;

public:
	ColliderRect();
	bool GetCollisionWithRect(ColliderRect* object);
	bool GetCollisionWithSphere(ColliderSphere* object);
};

