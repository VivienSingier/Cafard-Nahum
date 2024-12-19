#include "pch.h"
#include "TwoFaceCross1.h"
#include "TwoFaceCross2.h"
#include "GameManager.h"
#include "ColliderSphere.h"
#include "Ressources.h"
#include "Player.h"
#include "SceneManager.h"
#include "Room.h"

TwoFaceCross1::TwoFaceCross1(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["TwoFaceCross1"],
		sf::Vector2f(x, y), sf::Vector2f(2, 2), direction)
{
	damage = 1;
	this->setOrigin(18, 12);

	spawnClock.restart();

	c1 = new ColliderSphere(8, x - 6 * direction.x, y - 6 *direction.y);
	c2 = new ColliderSphere(8, x + 6 * direction.x, y + 6 * direction.y);
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

void TwoFaceCross1::SpawnChildBullets()
{
	if (spawnClock.getElapsedTime().asSeconds() > 0.25f)
	{
		float angle = 0;
		if (speed.y > 0)
		{
			angle = 90;
		}
		else if (speed.y < 0)
		{
			angle = 270;
		}
		else if (speed.x < 0)
		{
			angle = 180;
		}
		float angle1 = angle + 30;
		float radians = 3.1415926536 / 180 * angle1;
		float x = 1.f * cos(radians);
		float y = -1.f * -sin(radians);

		TwoFaceCross2* newB = new TwoFaceCross2(getPosition().x, getPosition().y, sf::Vector2f(x, y));
		newB->setRotation(angle);
		SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(newB);

		float angle2 = angle - 30;
		float radians2 = 3.1415926536 / 180 * angle2;
		float x2 = 1.f * cos(radians2);
		float y2 = -1.f * -sin(radians2);

		TwoFaceCross2* newB2 = new TwoFaceCross2(getPosition().x, getPosition().y, sf::Vector2f(x2, y2));
		newB2->setRotation(angle);
		SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(newB2);
		spawnClock.restart();
	}


}

void TwoFaceCross1::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
	SpawnChildBullets();
}

void TwoFaceCross1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Bullet::draw(target, states);
}
