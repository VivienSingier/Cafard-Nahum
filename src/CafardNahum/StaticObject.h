#pragma once
#include "Entity.h"
#include "ColliderRect.h"

class StaticObject : public Entity
{
protected:
	bool isWalkable;
public:
	ColliderRect* collisionRect;
	StaticObject(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, bool cIsWalkable);
	bool GetIsWalkable();
	void SetIsWalkable(bool IsWalkable);
};

