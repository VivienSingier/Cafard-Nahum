#include "pch.h"
#include "TwoFaceCross1.h"
#include "GameManager.h"
#include "ColliderSphere.h"
#include "Ressources.h"
#include "Player.h"

TwoFaceCross1::TwoFaceCross1(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["TwoFaceCross1"],
		sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{
	damage = 1;
	this->setOrigin(9, 6);

	c1 = new ColliderSphere(4, x - 3 * direction.x, y - 3 *direction.y);
	c2 = new ColliderSphere(4, x + 3 * direction.x, y + 3 * direction.y);
	colliders.push_back(c1);
	colliders.push_back(c2);
}

void TwoFaceCross1::Move(float deltatime)
{
	move(sf::Vector2f(150 * deltatime * speed.x, 150 * deltatime * speed.y));
	c1->Move(150 * deltatime * speed.x, 150 * deltatime * speed.y);
	c2->Move(150 * deltatime * speed.x, 150 * deltatime * speed.y);
}

void TwoFaceCross1::HandleCollisions()
{
	Bullet::HandleCollisions();
	Player* p = GameManager::getInstance()->GetPlayer();
	for (int i = 0; i < colliders.size(); i++)
	{
		if (colliders[i]->GetCollisionWithSphere(p->c1))
		{
			needsToBeDestroyed = true;
			p->TakeDamage(damage);
		}
	}
}

void TwoFaceCross1::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
}

void TwoFaceCross1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Bullet::draw(target, states);
}
