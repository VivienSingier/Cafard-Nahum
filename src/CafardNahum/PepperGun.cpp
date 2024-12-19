#include "pch.h"
#include "PepperGun.h"
#include "Ressources.h"
#include "Room.h"
#include "SceneManager.h"
#include "Salt.h"
#include "Pepper.h"

PepperGun::PepperGun(float x, float y) :
	Weapon(&StaticTextures::GetInstance()->Weapons["PepperGun"], sf::Vector2f(x, y), sf::Vector2f(1, 1), sf::Vector2f(1, 1), 0.1f)
{
	this->setOrigin(0, 8);
	bulletType = 0;
}

void PepperGun::Rotate(float angle)
{
	this->setRotation(angle);
}

void PepperGun::Shoot(float angle)
{
	float radians = 3.1415926536 / 180 * angle;
	float x = 1.f * cos(radians);
	float y = -1.f * -sin(radians);

	Bullet* newB;
	if (bulletType == 0)
	{
		newB = new Salt(this->getPosition().x, this->getPosition().y, sf::Vector2f(x, y));
	}
	else
	{
		newB = new Pepper(this->getPosition().x, this->getPosition().y, sf::Vector2f(x, y));
	}

	SceneManager::GetInstance()->GetCurrentScene()->entities.push_back(newB);

	bulletType += 1;
	bulletType %= 2;
}
