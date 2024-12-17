#pragma once
#include "Boss.h"

class TwoFace : public Boss
{
public:
	TwoFace(sf::Vector2f position);

	void Shoot();
};

