#pragma once
#include "Movable.h"
#include "Entity.h"
#include "Alive.h"
#include "ColliderSphere.h"
#include <vector>

class Enemy : public Entity, public Alive, public Movable, public ColliderSphere
{
	int damage;

public:
	Enemy(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth);

	void Move(float deltatime) override;

	void GetShotAngle();
	virtual void Shoot();

};

