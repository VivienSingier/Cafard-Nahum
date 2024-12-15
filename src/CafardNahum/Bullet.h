#pragma once
#include "Movable.h"
#include "Entity.h"
#include "ColliderSphere.h"
#include <vector>


class Bullet : public Entity, public Movable, public ColliderSphere
{
public:
	Bullet(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed);
};