#include "pch.h"
#include "TwoFaceSpiral.h"
#include "GameManager.h"
#include "ColliderSphere.h"
#include "Ressources.h"
#include "Player.h"

TwoFaceSpiral::TwoFaceSpiral(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["TwoFaceSpiral"],
		sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{
	damage = 1;
	this->setOrigin(sf::Vector2f(9, 9));
	c1 = new ColliderSphere(8, x, y);
	colliders.push_back(c1);
}

void TwoFaceSpiral::Move(float deltatime)
{
	move(sf::Vector2f(100 * deltatime * speed.x, 100 * deltatime * speed.y));
	c1->Move(100 * deltatime * speed.x, 100 * deltatime * speed.y);
}

void TwoFaceSpiral::HandleCollisions()
{
	Bullet::HandleCollisions();
	Player* p = GameManager::getInstance()->GetPlayer();
	if (colliders[0]->GetCollisionWithSphere(p->c1))
	{
		needsToBeDestroyed = true;
		p->TakeDamage(damage);
	}
}

void TwoFaceSpiral::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
}

void TwoFaceSpiral::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Bullet::draw(target, states);
}