#include "pch.h"
#include "PoisonRoach.h"
#include "Ressources.h"
#include "GameManager.h"
#include "ColliderSphere.h"
#include <iostream>

PoisonRoach::PoisonRoach(sf::Vector2f position) :
	Enemy(&StaticTextures::GetInstance()->poisonRoachWalkCycleR[0], position,
		sf::Vector2f(1.5f, 1.5f), sf::Vector2f(100.f, 100.f), 15)
{
	isMoving = false;
	targetPos = sf::Vector2f(0, 0);

	actionClock.restart();
	shootingClock.restart();

	c = new ColliderSphere(32, this->getPosition().x, this->getPosition().y);

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

		if (abs(distanceX) > 0.1 || abs(distanceY) > 0.1)
		{
			Move(x, y, deltatime);
		}
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

void PoisonRoach::Move(float x, float y, float deltatime)
{
	//float enemyPositionX = this->getPosition().x;
	//float enemyPositionY = this->getPosition().y;
	//float playerPositionX = GameManager::getInstance()->GetPlayer()->getPosition().x;
	//float playerPositionY = GameManager::getInstance()->GetPlayer()->getPosition().y;

	//float distanceX = playerPositionX - enemyPositionX;
	//float distanceY = playerPositionY - enemyPositionY;

	//if (distanceX > 150.f)
	//{
	//	move(speed.x * deltatime, 0);
	//}
	//if (distanceX < -224.5f)
	//{
	//	move(-speed.x * deltatime, 0);
	//}
	//if (distanceY > 150.f)
	//{
	//	move(0, speed.y * deltatime);
	//}
	//if (distanceY < -244.5f)
	//{
	//	move(0, -speed.y * deltatime);
	//}
	move(x * speed.x * deltatime, y * speed.x * deltatime);
	c->Move(x * speed.x * deltatime, y * speed.x * deltatime);

}

void PoisonRoach::MultiShot()
{
	/*std::cout << "Multishot" << std::endl;*/
}

void PoisonRoach::Shoot()
{
	if (shootingClock.getElapsedTime().asSeconds() > 0.5)
	{
		/*std::cout << "Poison Shot" << std::endl;*/
		shootingClock.restart();
	}
}

void PoisonRoach::Update(float deltatime)
{
	HandleMovement(deltatime);
}

void PoisonRoach::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Enemy::draw(target, states);
	target.draw(c->sphere);
}
