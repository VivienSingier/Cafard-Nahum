#pragma once
#include "Entity.h"
#include "Movable.h"
#include "Bullet.h"
#include <vector>

class Weapon : public Entity, public Movable
{
public:
	Weapon(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed);
	virtual void Rotate(float angle) {}
	virtual void Shoot(float angle) {}
	virtual void Move(float x, float y);
};

