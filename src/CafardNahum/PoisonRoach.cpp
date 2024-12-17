#include "pch.h"
#include "PoisonRoach.h"
#include "Ressources.h"
#include "GameManager.h"
#include "Room.h"
#include "ColliderSphere.h"
#include "StaticObject.h"
#include "PoisonBullet1.h"
#include "PoisonBullet2.h"
#include <iostream>

PoisonRoach::PoisonRoach(sf::Vector2f position) :
	Enemy(&StaticTextures::GetInstance()->poisonRoachWalkCycleR[0], position,
		sf::Vector2f(1.5f, 1.5f), sf::Vector2f(100.f, 100.f), 15)
{
	this->setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	isMoving = false;
	targetPos = sf::Vector2f(0, 0);

	actionClock.restart();
	shootingClock.restart();

	c = new ColliderSphere(25, this->getPosition().x, this->getPosition().y);
	mainColliders.push_back(c);
	
	cN = new ColliderSphere(1, getPosition().x, this->getPosition().y - 15);
	cS = new ColliderSphere(1, getPosition().x, this->getPosition().y + 15);
	cE = new ColliderSphere(1, getPosition().x + 15, this->getPosition().y);
	cO = new ColliderSphere(1, getPosition().x - 15, this->getPosition().y);
}

void PoisonRoach::HandleMovement(float deltatime)
{ 
	if (!isMoving)
	{
		// Début du cycle
		targetPos = GameManager::getInstance()->GetPlayer()->getPosition();
		actionClock.restart();
		isMoving = true;
	}
	else if (actionClock.getElapsedTime().asSeconds() < 3.0 && isMoving)
	{
		// Déplacement et tirs simples

		float enemyPositionX = this->getPosition().x;
		float enemyPositionY = this->getPosition().y;
		float playerPositionX = targetPos.x;
		float playerPositionY = targetPos.y;

		float distanceX = enemyPositionX  - playerPositionX;
		float distanceY = enemyPositionY  - playerPositionY;

		float x = (distanceX < 0) - (distanceX > 0);
		float y = (distanceY < 0) - (distanceY > 0);

		if (abs(distanceX) <= 0.1) x = 0;
		if (abs(distanceY) <= 0.1) y = 0;
		HandleCollision(x, y, deltatime);
		Shoot();
	}
	else if (actionClock.getElapsedTime().asSeconds() >= 5.0 && isMoving)
	{
		//Tir chargé
		MultiShot();
		actionClock.restart();
		isMoving = false;
	}

}

void PoisonRoach::HandleCollision(float x, float y, float deltatime)
{
	std::vector <StaticObject*> StObj = SceneManager::GetInstance()->GetCurrentScene()->GetStatics();
	if (x > 0)
	{
		if (CheckCollisionWall(StObj, cE))
		{
			x = 0;
		}
	}
	if (x < 0)
	{
		if (CheckCollisionWall(StObj, cO))
		{
			x = 0;
		}
	}
	if (y > 0)
	{
		if (CheckCollisionWall(StObj, cS))
		{
			y = 0;
		}
	}
	if (y < 0)
	{
		if (CheckCollisionWall(StObj, cN))
		{
			y = 0;
		}
	}
	Move(x * speed.x * deltatime, y * speed.y * deltatime);
}

bool PoisonRoach::CheckCollisionWall(std::vector <StaticObject*> stObjVect, ColliderSphere* sphere)
{
	for (int i = 0; i < stObjVect.size(); i++)
	{
		if (!stObjVect[i]->GetIsWalkable())
		{
			if (sphere->GetCollisionWithRect(stObjVect[i]->collisionRect))
			{
				return true;
			}
		}
	}
	return false;
}

void PoisonRoach::Move(float x, float y)
{
	move(x, y);
	c->Move(x, y);
	cN->Move(x, y);
	cS->Move(x, y);
	cE->Move(x, y);
	cO->Move(x, y);
}

void PoisonRoach::MultiShot()
{
	for (int i = 0; i < 12; i++)
	{
		float angle = 0 + 30 * i;
		float radians = 3.1415926536 / 180 * angle;
		float x = 1.f * cos(radians);
		float y = -1.f * -sin(radians);

		PoisonBullet2* newB = new PoisonBullet2(getPosition().x, getPosition().y, sf::Vector2f(x, y));
		newB->setRotation(angle);
		SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(newB);
		shootingClock.restart();
	}
}

void PoisonRoach::Shoot()
{
	if (shootingClock.getElapsedTime().asSeconds() > 0.8)
	{
		float angle = GetShotAngle();
		float radians = 3.1415926536 / 180 * angle;
		float x = 1.f * cos(radians);
		float y = -1.f * -sin(radians);

		PoisonBullet1* newB = new PoisonBullet1(getPosition().x, getPosition().y, sf::Vector2f(x, y));
		newB->setRotation(angle);
		SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(newB);
		shootingClock.restart();
	}
}

void PoisonRoach::TakeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
	if (health == 0)
	{
		needsToBeDestroyed = true;
	}
	std::cout << health << std::endl;
}

void PoisonRoach::Update(float deltatime)
{
	HandleMovement(deltatime);
}

void PoisonRoach::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Enemy::draw(target, states);
}
