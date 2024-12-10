#pragma once
#include "Entity.h"
#include "ColliderRect.h"

class StaticObject : public Entity, public ColliderRect
{
	bool IsWalkable;
};

