#include "pch.h"
#include "MayoBullet1.h"
#include "MayoBottle.h"
#include "Room.h"
#include "SceneManager.h"


MayoBottle::MayoBottle(float x, float y) :
	Weapon("../../../res/Weapon/mayo.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(x, y), sf::Vector2f(1, 1), sf::Vector2f(1, 1))
{
	this->setOrigin(0, 8);
}

void MayoBottle::Rotate(float angle)
{
	this->setRotation(angle);
}

void MayoBottle::Shoot(float angle)
{
	float radians = 3.1415926536 / 180 * angle;

	//x and y
	float x = 500.f * cos(radians);
	float y = 500.f * -sin(radians);

	MayoBullet1* bullet = new MayoBullet1(this->getPosition().x, this->getPosition().y, sf::Vector2f(x, y));
	bullet->setRotation(angle);
	SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(bullet);
}
