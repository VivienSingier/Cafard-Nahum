#pragma once
#include "Movable.h"
#include "Entity.h"
#include "Alive.h"
#include "ColliderSphere.h"
#include <vector>

class Enemy : public Entity, public Alive, public Movable, public ColliderSphere
{
	int damage;

public:
	void Move(float deltatime) override;

	void GetShotAngle();
	virtual void Shoot();

};

