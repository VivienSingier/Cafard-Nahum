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

	c = new ColliderSphere(25, this->getPosition().x + sprite.getGlobalBounds().width / 2, this->getPosition().y + sprite.getGlobalBounds().height / 2);
	cN = new ColliderSphere(1, getPosition().x + sprite.getGlobalBounds().width / 2, this->getPosition().y + 15);
	cS = new ColliderSphere(1, getPosition().x + sprite.getGlobalBounds().width / 2, this->getPosition().y + 35);
	cE = new ColliderSphere(1, getPosition().x + sprite.getGlobalBounds().width - 15, this->getPosition().y + sprite.getGlobalBounds().height / 2);
	cO = new ColliderSphere(1, getPosition().x + 15, this->getPosition().y + sprite.getGlobalBounds().height / 2);
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

void PoisonRoach::HandleCollision(float deltatim)
{

}

void PoisonRoach::Move(float x, float y, float deltatime)
{

	move(x * speed.x * deltatime, y * speed.x * deltatime);
	c->Move(x * speed.x * deltatime, y * speed.x * deltatime);
	cN->Move(x * speed.x * deltatime, y * speed.x * deltatime);
	cS->Move(x * speed.x * deltatime, y * speed.x * deltatime);
	cE->Move(x * speed.x * deltatime, y * speed.x * deltatime);
	cO->Move(x * speed.x * deltatime, y * speed.x * deltatime);
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
	target.draw(cN->sphere);
	target.draw(cS->sphere);
	target.draw(cE->sphere);
	target.draw(cO->sphere);
}
