#include "pch.h"
#include "MayoBullet1.h"
#include "MayoBottle.h"
#include "Ressources.h"
#include "Room.h"
#include "SceneManager.h"


MayoBottle::MayoBottle(float x, float y) :
	Weapon(&StaticTextures::GetInstance()->Weapons["MayoBottle"], sf::Vector2f(x, y), sf::Vector2f(1, 1), sf::Vector2f(1, 1), 0.5f)
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
	float x = 1.f * cos(radians);
	float y = -1.f * -sin(radians);

	MayoBullet1* bullet = new MayoBullet1(this->getPosition().x, this->getPosition().y, sf::Vector2f(x, y));
	bullet->setRotation(angle);
	SceneManager::GetInstance()->GetCurrentScene()->entities.push_back(bullet);

	radians = 3.1415926536 / 180 * (angle + 15);
	x = 1.f * cos(radians);
	y = -1.f * -sin(radians);

	MayoBullet1* bullet2 = new MayoBullet1(this->getPosition().x, this->getPosition().y, sf::Vector2f(x, y));
	bullet2->setRotation(angle);
	SceneManager::GetInstance()->GetCurrentScene()->entities.push_back(bullet2);

	radians = 3.1415926536 / 180 * (angle - 15);
	x = 1.f * cos(radians);
	y = -1.f * -sin(radians);

	MayoBullet1* bullet3 = new MayoBullet1(this->getPosition().x, this->getPosition().y, sf::Vector2f(x, y));
	bullet3->setRotation(angle);
	SceneManager::GetInstance()->GetCurrentScene()->entities.push_back(bullet3);
}
