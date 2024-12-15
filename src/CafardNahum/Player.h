#pragma once
#include "Entity.h"
#include "Alive.h"
#include "Movable.h"
#include "ColliderSphere.h"
#include <vector>

class Weapon;
class Bullet;

class Player : public Entity, public Movable, public Alive, public ColliderSphere
{
	Weapon* holdWeapon;
	Weapon* secondaryWeapon;
	sf::Vector2f UnitVector;
	bool changeWeapon;
	bool isShooting;

public:
	Player(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f cSpeed);

	void Update(float deltatime) override;
	void Move(float deltatime) override;
	void WeaponChange(Weapon* holdWeapon, Weapon* secondaryWeapon);
	void GetShotAngle();
	void Shoot(std::vector <Bullet*> PlayerProjectiles);

};

