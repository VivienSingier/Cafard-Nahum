#pragma once
#include "Bullet.h"

class PoisonBullet1 : public Bullet
{

	ColliderSphere* c1;
public:
	PoisonBullet1(float x, float y, sf::Vector2f direction);
	void Move(float deltatime) override;
	void HandleCollisions() override;
	void Update(float deltatime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

