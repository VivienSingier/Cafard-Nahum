#pragma once
#include "Enemy.h"
#include "Bullet.h"

class PoisonRoach : public Enemy
{

public:
	PoisonRoach(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth);

	void Move(float deltatime) override;
	void Shoot(std::vector <Bullet*> EnemyBullets);

};


