#pragma once
#include "Movable.h"
#include "Entity.h"

class Bullet : public Entity, public Movable
{
	int damage;

public:
	void Move(float deltatime) override;
};

