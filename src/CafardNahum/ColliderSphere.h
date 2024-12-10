#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class ColliderRect;

class ColliderSphere
{
protected:
	std::vector <sf::CircleShape*> spheres;

public:
	ColliderSphere();
	bool GetCollisionWithRect(ColliderRect* object);
	bool GetCollisionWithSphere(ColliderSphere* object);
};

