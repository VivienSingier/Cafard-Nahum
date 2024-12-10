#pragma once
#include "Enemy.h"
#include "Bullet.h"

class PoisonRoach : public Enemy
{

public:
	PoisonRoach(int x, int y);

	void Move(float deltatime) override;
	void Shoot(std::vector <Bullet*> EnemyBullets);

};

