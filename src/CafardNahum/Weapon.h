#pragma once
#include "Entity.h"
#include "Movable.h"
#include "Bullet.h"
#include <vector>

class Weapon : public Entity, public Movable
{


public:
	virtual void Shoot(std::vector <Bullet*> playerBullets);
};

