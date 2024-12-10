#pragma once
#include "Movable.h"
#include "Entity.h"
#include "Alive.h"
#include <vector>

class Enemy : public Entity, public Alive, public Movable
{
	int damage;

public:
	void Move(float deltatime) override;

	void GetShotAngle();
	virtual void Shoot();

};

