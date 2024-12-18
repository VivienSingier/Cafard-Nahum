#pragma once
#include "Boss.h"

class ColliderSphere;

class TwoFace : public Boss
{
	sf::Clock behaviourClock;
	sf::Clock spiralClock;

	ColliderSphere* c1;

	int spiralAngle;
	bool hasCrossShot;

public:
	TwoFace(sf::Vector2f position);

	void HandleBehaviour();
	void SpiralShot();
	void SeekingShot();
	void CrossShots();
	void Update(float deltatime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

