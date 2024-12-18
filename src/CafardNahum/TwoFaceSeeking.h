#pragma once
#include "Bullet.h"

class ColliderSphere;

class TwoFaceSeeking :
    public Bullet
{
	ColliderSphere* c1;
	sf::Clock liveClock;
	sf::Clock spawnClock;

public:
	TwoFaceSeeking(float x, float y, sf::Vector2f direction);
	void Move(float deltatime) override;
	void HandleCollisions() override;
	void SetAngle();
	void Update(float deltatime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

