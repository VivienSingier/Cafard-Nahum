#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class ColliderRect
{

};


class ColliderSphere
{
	std::vector <sf::CircleShape*> spheres;

public:
	bool GetCollisionWithRect(ColliderRect* object);
	bool GetCollisionWithSphere(ColliderSphere* object);
};

