#pragma once
#include "Enemy.h"
#include "Bullet.h"

class PoisonRoach : public Enemy
{

public:
	PoisonRoach(sf::Texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth);

	void Shoot(std::vector <Bullet*> EnemyBullets);

};


