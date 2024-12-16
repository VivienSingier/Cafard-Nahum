#include "pch.h"
#include "PoisonRoach.h"
#include "Bullet.h"
#include "BulletPoisonRoach.h"
#include "GameManager.h"
#include "iostream"

PoisonRoach::PoisonRoach(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f speed) :
	Enemy(path, textureRect, position, scale, cHealth, speed )
{
	 
}

void PoisonRoach::Update(float deltatime)
{
	EnemyMove(deltatime);
	Shoot(SceneManager::getInstance()->GetCurrentScene()->EnemyProjectiles);
}

void PoisonRoach::EnemyMove(float deltatime)
{
	float enemyPositionX = this->getPosition().x;
	float enemyPositionY = this->getPosition().y;
	float playerPositionX = GameManager::getInstance()->GetPlayer()->getPosition().x;
	float playerPositionY = GameManager::getInstance()->GetPlayer()->getPosition().y;

	float distanceX = playerPositionX - enemyPositionX;
	float distanceY = playerPositionY - enemyPositionY;

	if (distanceX > 150.f)
	{
		move(speed.x * deltatime, 0);
	}
	if (distanceX < -224.5f)
	{
		move(-speed.x * deltatime, 0);
	}
	if (distanceY > 150.f)
	{
		move(0, speed.y * deltatime);
	}
	if (distanceY < -244.5f)
	{
		move(0, -speed.y * deltatime);
	}
}

void PoisonRoach::Shoot(std::vector <Bullet*> EnemyBullets)
{
	static sf::Clock shootClock;

	if (shootClock.getElapsedTime().asSeconds() >3.0f)
	{
		float enemyPositionX = sprite.getPosition().x;
		float enemyPositionY = sprite.getPosition().y;
		float playerPositionX = GameManager::getInstance()->GetPlayer()->getPosition().x;
		float playerPositionY = GameManager::getInstance()->GetPlayer()->getPosition().y;

		sf::Vector2f ShootVector = sf::Vector2f(playerPositionX - enemyPositionX, playerPositionY - enemyPositionY);

		BulletPoisonRoach* newBullet = new BulletPoisonRoach("../../../res/Bullet/BulletPoisonRoach.png", sf::IntRect(1, 1, 18, 7), sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y), sf::Vector2f(1, 1), sf::Vector2f(ShootVector));
		EnemyBullets.push_back(newBullet);
		std::cout << "Attack" << std::endl;

		shootClock.restart();
	} 
}