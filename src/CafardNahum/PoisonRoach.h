#pragma once
#include "Enemy.h"

class Bullet;

class PoisonRoach : public Enemy
{
	sf::Clock actionClock;
	bool isMoving;
	bool hasAttacked;
	sf::Vector2f targetPos;

public:
	PoisonRoach(sf::Vector2f position);

	void HandleMovement(float deltatime);
	void Update(float deltatime) override;
	void Move(float x, float y);
	void Shoot();
};


