#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "ColliderRect.h"

class ColliderSphere
{
	std::vector <sf::CircleShape*> spheres;

public:
	bool GetCollisionWithRect(ColliderRect* object);
	bool GetCollisionWithSphere(ColliderSphere* object);
};

