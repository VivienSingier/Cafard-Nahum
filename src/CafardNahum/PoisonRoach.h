#pragma once
#include "Enemy.h"

class Bullet;

class PoisonRoach : public Enemy
{
	sf::Clock actionClock;
	sf::Clock shootingClock;
	bool isMoving;
	sf::Vector2f targetPos;

	ColliderSphere* c;
	//ColliderSphere cN;
	//ColliderSphere cS;
	//ColliderSphere cE;
	//ColliderSphere cO;

public:
	PoisonRoach(sf::Vector2f position);

	void HandleMovement(float deltatime);
	void Update(float deltatime) override;
	void Move(float x, float y, float deltatime);
	void MultiShot();
	void Shoot();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


