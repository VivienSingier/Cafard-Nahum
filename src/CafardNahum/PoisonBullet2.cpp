#include "pch.h"
#include "PoisonBullet2.h"
#include "GameManager.h"
#include "ColliderSphere.h"
#include "Ressources.h"
#include "Player.h"

PoisonBullet2::PoisonBullet2(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["PoisonBullet2"],
		sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{
	damage = 1;
	this->setOrigin(sf::Vector2f(9, 9));

	c1 = new ColliderSphere(8, x, y);
	colliders.push_back(c1);
}

void PoisonBullet2::Move(float deltatime)
{
	move(sf::Vector2f(150 * deltatime * speed.x, 150 * deltatime * speed.y));
	c1->Move(150 * deltatime * speed.x, 150 * deltatime * speed.y);
}

void PoisonBullet2::HandleCollisions()
{
	Bullet::HandleCollisions();
	Player* p = GameManager::getInstance()->GetPlayer();
	if (colliders[0]->GetCollisionWithSphere(p->c1))
	{
		needsToBeDestroyed = true;
		p->TakeDamage(damage);
	}
}

void PoisonBullet2::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
}

void PoisonBullet2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Bullet::draw(target, states);
}
