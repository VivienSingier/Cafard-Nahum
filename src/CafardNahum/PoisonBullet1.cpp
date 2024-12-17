#include "pch.h"
#include "PoisonBullet1.h"
#include "ColliderSphere.h"
#include "Ressources.h"

PoisonBullet1::PoisonBullet1(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["PoisonBullet1"],
		sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{
	damage = 1;
	this->setOrigin(sf::Vector2f(0, 7));

	c1 = new ColliderSphere(5, x, y);
	c1->Move(direction.x * 13.f, direction.y * 13.f);
	colliders.push_back(c1);
}

void PoisonBullet1::Move(float deltatime)
{
	move(sf::Vector2f(400 * deltatime * speed.x, 400 * deltatime * speed.y));
	c1->Move(400 * deltatime * speed.x, 400 * deltatime * speed.y);
}

void PoisonBullet1::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
}
