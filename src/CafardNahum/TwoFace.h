#pragma once
#include "Boss.h"

class TwoFace : public Boss
{
	sf::Clock behaviourClock;
	sf::Clock spiralClock;

	int spiralAngle;
	bool hasCrossShot;

public:
	TwoFace(sf::Vector2f position);

	void HandleBehaviour();
	void Shoot();
	void SpiralShot();
	void SeekingShot();
	void CrossShots();
	void Update(float deltatime) override;
};

