#pragma once
#include "Entity.h"
#include "Alive.h"
#include "Movable.h"
#include "Weapon.h"
#include "Bullet.h"
#include "ColliderSphere.h"
#include <vector>

class Player : public Entity, public Movable, public Alive, public ColliderSphere
{
	Weapon* holdWeapon;
	Weapon* secondaryWeapon;

public:
	void Move(float deltatime) override;

	void HandleInput();
	void GetShotAngle();
	void Shoot(std::vector <Bullet*> PlayerProjectiles);

};

