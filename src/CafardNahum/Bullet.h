#pragma once
#include "Movable.h"
#include "Entity.h"
#include "ColliderSphere.h"

class Bullet : public Entity, public Movable
{
protected:
	int damage;

public:
	Bullet(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed);
	virtual void HandleCollisions() {}
};

