#pragma once
#include "Enemy.h"

class Bullet;

class PoisonRoach : public Enemy
{

	sf::Clock clock;

public:
	PoisonRoach(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f speed);

	void Update(float deltatime) override;
	void EnemyMove(float deltatime) override;
	void Shoot(std::vector <Bullet*> EnemyBullets) override;
};


