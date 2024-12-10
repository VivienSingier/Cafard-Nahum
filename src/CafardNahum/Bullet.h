#pragma once
#include "Movable.h"
#include "Entity.h"
#include "ColliderSphere.h"

class Bullet : public Entity, public Movable, public ColliderSphere
{
	int damage;

public:
	void Move(float deltatime) override;
};

