#pragma once
#include "Movable.h"
#include "Entity.h"
#include "Alive.h"
#include "ColliderSphere.h"
#include <vector>

class GameManager;
class Bullet;

class Enemy : public Entity, public Alive, public Movable, public ColliderSphere
{
public:
	Enemy(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f speed);

	void Update(float deltatime) override;
	void GetAngle(sf::Vector2f target);
	virtual void EnemyMove(float deltatime) {}
	virtual void Shoot(std::vector <Bullet*> EnemyBullets) {}

};

