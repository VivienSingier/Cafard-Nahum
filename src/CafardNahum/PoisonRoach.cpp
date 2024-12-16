#include "pch.h"
#include "PoisonRoach.h"
#include "Ressources.h"
#include "GameManager.h"

PoisonRoach::PoisonRoach(sf::Vector2f position) :
	Enemy(&StaticTextures::GetInstance()->poisonRoachWalkCycleR[0], position,
		sf::Vector2f(1.5f, 1.5f), sf::Vector2f(150.f, 150.f), 15)
{
	isMoving = false;
	hasAttacked = false;
	targetPos = sf::Vector2f(0, 0);
}

void PoisonRoach::HandleMovement(float deltatime)
{ 
	if (!isMoving && !hasAttacked)
	{
		int xDirection = rand() % 2;
		int yDirection = rand() % 2;
		if (xDirection == 0) xDirection = -1;
		if (yDirection == 0) yDirection = -1;

		float enemyPositionX = this->getPosition().x;
		float enemyPositionY = this->getPosition().y;
		float playerPositionX = GameManager::getInstance()->GetPlayer()->getPosition().x;
		float playerPositionY = GameManager::getInstance()->GetPlayer()->getPosition().y;

		float distanceX = abs(enemyPositionX + 70 * xDirection - playerPositionX);
		float distanceY = abs(enemyPositionY + 70 * yDirection - playerPositionY);

		if (dis)
		
	}
}

void PoisonRoach::Move(float x, float y)
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
	move(x * speed.x, y*speed.x)

}

void PoisonRoach::Shoot()
{

}

void PoisonRoach::Update(float deltatime)
{
	Move(deltatime);
	Shoot();
}
