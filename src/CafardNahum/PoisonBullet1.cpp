#include "pch.h"
#include "PoisonBullet1.h"
#include "GameManager.h"
#include "ColliderSphere.h"
#include "Ressources.h"
#include "Player.h"

PoisonBullet1::PoisonBullet1(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["PoisonBullet1"],
		sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{
	damage = 1;
	this->setOrigin(sf::Vector2f(0, 6));

	c1 = new ColliderSphere(5, x, y);
	c1->Move(direction.x * 11.f, direction.y * 11.f);
	colliders.push_back(c1);
}

void PoisonBullet1::Move(float deltatime)
{
	move(sf::Vector2f(300 * deltatime * speed.x, 300 * deltatime * speed.y));
	c1->Move(300 * deltatime * speed.x, 300 * deltatime * speed.y);
}

void PoisonBullet1::HandleCollisions()
{
	Bullet::HandleCollisions();
	Player* p = GameManager::getInstance()->GetPlayer();
	if (colliders[0]->GetCollisionWithSphere(p->c1))
	{
		needsToBeDestroyed = true;
		p->TakeDamage(damage);
	}
}

void PoisonBullet1::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
}

void PoisonBullet1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Bullet::draw(target, states);
}