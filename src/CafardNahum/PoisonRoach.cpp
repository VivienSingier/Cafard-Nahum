#include "pch.h"
#include "PoisonRoach.h"
#include "Bullet.h"
#include "BulletPoisonRoach.h"
#include "GameManager.h"

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
	sf::Vector2f vector;
	Enemy::GetAngle(vector);
	float vectorNorm = sqrt(vector.x * vector.x + vector.y * vector.y);
	if (vectorNorm >= 200.f)
	{
		sf::Vector2f VectorMove = sf::Vector2f(vector.x / vectorNorm, vector.y / vectorNorm);
		sprite.move(VectorMove.x * deltatime, VectorMove.y * deltatime);
	}
	else
	{
		sprite.move(0, 0);
	}
}

void PoisonRoach::Shoot(std::vector <Bullet*> EnemyBullets)
{
	sf::Vector2f vector;
	GetAngle(vector);
	float vectorNorm = sqrt(vector.x * vector.x + vector.y * vector.y);
	sf::Vector2f ShootVector = sf::Vector2f(vector.x / vectorNorm, vector.y / vectorNorm);
	BulletPoisonRoach* newBullet = new BulletPoisonRoach("../../../res/Bullet/BulletPoisonRoach.png", sf::IntRect(1, 1, 18, 7), sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y), sf::Vector2f(1, 1), sf::Vector2f(ShootVector));
	EnemyBullets.push_back(newBullet);
	
}