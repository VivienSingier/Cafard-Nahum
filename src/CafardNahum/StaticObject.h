#pragma once
#include "Entity.h"
#include "ColliderRect.h"

class StaticObject : public Entity
{
protected:
	bool isWalkable;
public:
	ColliderRect* collisionRect;
	StaticObject(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, bool cIsWalkable);
	bool GetIsWalkable();
	void SetIsWalkable(bool IsWalkable);
};

