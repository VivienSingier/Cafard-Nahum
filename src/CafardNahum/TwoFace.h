#pragma once
#include "Boss.h"
#include "Bullet.h"

class TwoFace : public Boss
{
public:
	TwoFace(int x, int y);

	void Move(float deltatime) override;
	void Shoot(std::vector <Bullet*> EnemyBullets);
};

