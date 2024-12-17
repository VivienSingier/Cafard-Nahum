#pragma once
#include "Movable.h"
#include "Entity.h"
#include "Alive.h"
#include <vector>

class ColliderSphere;

class Enemy : public Entity, public Alive, public Movable
{
	int damage;

public:
	std::vector <ColliderSphere*> mainColliders;

	Enemy(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth);

	float GetShotAngle();
	virtual void Shoot() {}

};

