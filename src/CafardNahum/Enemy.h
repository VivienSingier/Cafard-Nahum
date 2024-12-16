#pragma once
#include "Movable.h"
#include "Entity.h"
#include "Alive.h"
#include "ColliderSphere.h"
#include <vector>

class Enemy : public Entity, public Alive, public Movable
{
	int damage;

public:
	Enemy(sf::Texture texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth);

	void GetShotAngle();
	virtual void Shoot() {}

};

