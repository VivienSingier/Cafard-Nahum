#pragma once
#include "Enemy.h"

class Bullet;
class StaticObject;
class ColliderSphere;

class PoisonRoach : public Enemy
{
	sf::Clock actionClock;
	sf::Clock shootingClock;
	bool isMoving;
	sf::Vector2f targetPos;

	ColliderSphere* c;
	ColliderSphere* cN;
	ColliderSphere* cS;
	ColliderSphere* cE;
	ColliderSphere* cO;

public:
	PoisonRoach(sf::Vector2f position);

	void HandleMovement(float deltatime);
	bool CheckCollisionWall(std::vector <StaticObject*> stObjVect, ColliderSphere* sphere);
	void HandleCollision(float x, float y, float deltatime);
	void Update(float deltatime) override;
	void TakeDamage(int damage) override;
	void Move(float x, float y);
	void MultiShot();
	void Shoot();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


