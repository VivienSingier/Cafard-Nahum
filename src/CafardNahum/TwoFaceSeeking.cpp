#include "pch.h"
#include "TwoFaceSeeking.h"
#include "TwoFaceSeekingChild.h"
#include "Ressources.h"
#include "ColliderSphere.h"
#include "GameManager.h"
#include "SceneManager.h"
#include "Room.h"
#include "Player.h"

TwoFaceSeeking::TwoFaceSeeking(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["TwoFaceSeeking"], 
		sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{
	damage = 1;
	setOrigin(0, 6);
	liveClock.restart();
	spawnClock.restart();

	c1 = new ColliderSphere(5, x, y);
	c1->Move(direction.x * 11.f, direction.y * 11.f);
	colliders.push_back(c1);
}

void TwoFaceSeeking::Move(float deltatime)
{
	move(sf::Vector2f(100 * deltatime * speed.x, 100 * deltatime * speed.y));
	c1->Move(100 * deltatime * speed.x, 100 * deltatime * speed.y);

	if (spawnClock.getElapsedTime().asSeconds() > 0.5f)
	{
		TwoFaceSeekingChild* newB = new TwoFaceSeekingChild(getPosition().x, getPosition().y);
		SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(newB);
		spawnClock.restart();
	}
}

void TwoFaceSeeking::SetAngle()
{
	sf::Vector2f playerPos = GameManager::getInstance()->GetPlayer()->getPosition();
	sf::Vector2f pos = getPosition();

	float angle = atan2((playerPos.y - pos.y), playerPos.x - pos.x);
	angle *= (180.0 / 3.141592653589793238463);

	float radians = 3.1415926536 / 180 * angle;
	float x = 1.f * cos(radians);
	float y = -1.f * -sin(radians);

	speed = sf::Vector2f(x, y);
	setRotation(angle);
}

void TwoFaceSeeking::HandleCollisions()
{
	Bullet::HandleCollisions();
	Player* p = GameManager::getInstance()->GetPlayer();
	if (colliders[0]->GetCollisionWithSphere(p->c1))
	{
		needsToBeDestroyed = true;
		p->TakeDamage(damage);
	}
}

void TwoFaceSeeking::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
	SetAngle();
	if (liveClock.getElapsedTime().asSeconds() > 4.5f)
	{
		needsToBeDestroyed = true;
	}
}

void TwoFaceSeeking::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Bullet::draw(target, states);
}
