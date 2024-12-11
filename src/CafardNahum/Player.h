#pragma once
#include "Entity.h"
#include "Alive.h"
#include "Movable.h"
#include "Weapon.h"
#include "Bullet.h"
#include "ColliderSphere.h"
#include "GameManager.h"
#include <vector>

class Player : public Entity, public Movable, public Alive, public ColliderSphere
{
	Weapon* holdWeapon;
	Weapon* secondaryWeapon;

public:
	Player(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f cSpeed);

	void GetShotAngle();
	void Shoot(std::vector <Bullet*> PlayerProjectiles);

};

