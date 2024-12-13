#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class ColliderRect;

class ColliderSphere 
{
public:
	sf::CircleShape sphere;

	ColliderSphere(float radius, float x, float y);
	bool GetCollisionWithRect(ColliderRect* object);
	bool GetCollisionWithSphere(ColliderSphere* object);
	void Move(float x, float y);
};

