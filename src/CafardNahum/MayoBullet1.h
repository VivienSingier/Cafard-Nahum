#pragma once
#include "Bullet.h"

class ColliderSphere;

class MayoBullet1 : public Bullet
{
	ColliderSphere* c1;

public:
	MayoBullet1(float x, float y, sf::Vector2f direction);
	void HandleCollisions() override;
	void Move(float deltatime) override;
	void Update(float deltatime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

