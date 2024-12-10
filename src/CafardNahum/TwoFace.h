#pragma once
#include "Boss.h"
#include "Bullet.h"

class TwoFace : public Boss
{
public:
	TwoFace(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth);

	void Move(float deltatime) override;
	void Shoot(std::vector <Bullet*> EnemyBullets);
};

