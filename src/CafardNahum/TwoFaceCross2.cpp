#include "pch.h"
#include "TwoFaceCross2.h"
#include "Ressources.h"
#include "Player.h"
#include "GameManager.h"

TwoFaceCross2::TwoFaceCross2(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["TwoFaceCross2"],
		sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{
	damage = 1;
	setOrigin(sf::Vector2f(8, 8));
	target = sf::Vector2f(getPosition().x + 150 * direction.x, getPosition().y + 150 * direction.y);

	c1 = new ColliderSphere(7, x , y );
	colliders.push_back(c1);

	liveClock.restart();
}

void TwoFaceCross2::Move(float deltatime)
{
	sf::Vector2f distance = sf::Vector2f(target.x - getPosition().x, target.y - getPosition().y);

	move(distance.x * deltatime, distance.y * deltatime);
	c1->Move(distance.x * deltatime, distance.y * deltatime);
}

void TwoFaceCross2::HandleCollisions()
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

void TwoFaceCross2::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
	if (liveClock.getElapsedTime().asSeconds() > 5.0f)
	{
		needsToBeDestroyed = true;
	}
}

void TwoFaceCross2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Bullet::draw(target, states);
}