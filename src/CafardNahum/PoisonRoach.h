#pragma once
#include "Enemy.h"

class Bullet;

class PoisonRoach : public Enemy
{
	sf::Clock actionClock;
	sf::Clock shootingClock;
	bool isMoving;
	sf::Vector2f targetPos;

public:
	PoisonRoach(sf::Vector2f position);

	void HandleMovement(float deltatime);
	void Update(float deltatime) override;
	void Move(float x, float y, float deltatime);
	void MultiShot();
	void Shoot();
};


