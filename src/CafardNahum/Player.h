#pragma once
#include "Entity.h"
#include "Alive.h"
#include "Movable.h"
#include <vector>

class Wall;
class Weapon;
class StaticObject;
class Bullet;
class ColliderRect;
class ColliderSphere;
class PlayerHealthBar;

class Player : public Entity, public Movable, public Alive 
{
	Weapon* holdWeapon;
	Weapon* secondaryWeapon;
	sf::Vector2f UnitVector;

	ColliderSphere* cO;
	ColliderSphere* cE;
	ColliderSphere* cN;
	ColliderSphere* cS;

	PlayerHealthBar* b;

public:
	ColliderSphere* c1;

	Player(sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f cSpeed);

	void Update(float deltatime) override;
	void Move(float x, float y);
	void HandleInput(float deltatime);
	bool CheckCollisionWall(std::vector <StaticObject*> stObjVect, ColliderSphere* sphere);
	void WeaponChange(Weapon* holdWeapon, Weapon* secondaryWeapon);
	float GetShotAngle();
	void TakeDamage(int damage) override;
	void Shoot();
	void draw(sf::RenderTarget& targer, sf::RenderStates states) const override;

};

