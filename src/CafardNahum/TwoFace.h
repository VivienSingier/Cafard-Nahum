#pragma once
#include "Boss.h"
#include "Bullet.h"

class TwoFace : public Boss
{
public:
	TwoFace(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth);

	void Shoot(std::vector <Bullet*> EnemyBullets);
};

