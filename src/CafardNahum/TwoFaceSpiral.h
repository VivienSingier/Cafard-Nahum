#pragma once
#include "Bullet.h"

class ColliderSphere;

class TwoFaceSpiral :
    public Bullet
{
    ColliderSphere* c1;
public:
	TwoFaceSpiral(float x, float y, sf::Vector2f direction);
	void Move(float deltatime) override;
	void HandleCollisions() override;
	void Update(float deltatime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

