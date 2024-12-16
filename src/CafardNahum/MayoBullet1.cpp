#include "pch.h"
#include "MayoBullet1.h"
#include "ColliderSphere.h"
#include "Ressources.h"

MayoBullet1::MayoBullet1(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["MayoBullet"], 
			 sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{
	damage = 3;
	this->setOrigin(sf::Vector2f(0, 6));

	c1 = new ColliderSphere(5, x, y);
	c1->Move(direction.x * 13.f, direction.y*13.f);
	colliders.push_back(c1);
}

void MayoBullet1::Move(float deltatime)
{
	move(sf::Vector2f(500 * deltatime * speed.x, 500 * deltatime * speed.y));
	c1->Move(500 * deltatime * speed.x, 500 * deltatime * speed.y);
}

void MayoBullet1::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
}
