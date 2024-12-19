#pragma once
#include "Bullet.h"

class ColliderSphere;

class Salt :
    public Bullet
{
	ColliderSphere* c1;
public:
	Salt(float x, float y, sf::Vector2f direction);
	void Move(float deltatime) override;
	void HandleCollisions() override;
	void Update(float deltatime) override;
};

