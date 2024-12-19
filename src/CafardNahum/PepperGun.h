#pragma once
#include "Weapon.h"

class PepperGun : public Weapon
{
	int bulletType;
public:
	PepperGun(float x, float y);
	void Rotate(float angle) override;
	void Shoot(float angle) override;
};

