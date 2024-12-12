#pragma once
#include "Entity.h"
#include "ColliderRect.h"

class StaticObject : public Entity, public ColliderRect
{
	bool isWalkable;
public:
	StaticObject(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, bool cIsWalkable);
	bool GetIsWalkable();
	void SetIsWalkable(bool IsWalkable);
};

