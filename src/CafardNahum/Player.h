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

class Player : public Entity, public Movable, public Alive 
{
	Weapon* holdWeapon;
	Weapon* secondaryWeapon;
	sf::Vector2f UnitVector;

	ColliderSphere* c1;
	ColliderSphere* cO;
	ColliderSphere* cE;
	ColliderSphere* cN;
	ColliderSphere* cS;

public:
	Player(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f cSpeed);

	void Update(float deltatime) override;
	void Move(float deltatime) override;
	bool CheckCollisionWall(std::vector <StaticObject*> stObjVect, ColliderSphere* sphere);
	void WeaponChange(Weapon* holdWeapon, Weapon* secondaryWeapon);
	void GetShotAngle();
	void Shoot(std::vector <Bullet*> PlayerProjectiles);
	void draw(sf::RenderTarget& targer, sf::RenderStates states) const override;

};

