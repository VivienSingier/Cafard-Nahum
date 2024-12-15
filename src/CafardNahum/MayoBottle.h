#pragma once
#include "Weapon.h"

class MayoBottle : public Weapon
{
public:
	MayoBottle(float x, float y);
	void Rotate(float angle) override;
	void Shoot(float angle) override;
};

