#include "pch.h"
#include "TwoFace.h"
#include "Ressources.h"
#include "TwoFaceSpiral.h"
#include "TwoFaceCross1.h"
#include "SceneManager.h"
#include "Room.h"
#include <iostream>

TwoFace::TwoFace(sf::Vector2f position) :
	Boss::Boss(&StaticTextures::GetInstance()->Boss["TwoFace"], position, sf::Vector2f(2, 2), sf::Vector2f(1, 1), 200)
{
	this->setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);

	behaviourClock.restart();
	spiralClock.restart();
	hasCrossShot = true;

	spiralAngle = 0;
}

void TwoFace::Shoot()
{

}

void TwoFace::SpiralShot()
{
	if (spiralClock.getElapsedTime().asSeconds() > 0.2f && spiralAngle < 180)
	{
		for (int i = 0; i < 6; i++)
		{
			float angle = spiralAngle + 60 * i;
			float radians = 3.1415926536 / 180 * angle;
			float x = 1.f * cos(radians);
			float y = -1.f * -sin(radians);

			TwoFaceSpiral* newB = new TwoFaceSpiral(getPosition().x, getPosition().y, sf::Vector2f(x, y));
			newB->setRotation(angle);
			SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(newB);
		}
		spiralClock.restart();
		spiralAngle += 20;
	}
	if (spiralAngle >= 180)
	{
		spiralAngle = 0;
	}
}

void TwoFace::SeekingShot()
{
	std::cout << "SeekingShot" << std::endl;
}

void TwoFace::CrossShots()
{
	std::cout << "CrossShots" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		float angle = 90 * i;
		float radians = 3.1415926536 / 180 * angle;
		float x = 1.f * cos(radians);
		float y = -1.f * -sin(radians);

		TwoFaceCross1* newB = new TwoFaceCross1(getPosition().x, getPosition().y, sf::Vector2f(x, y));
		newB->setRotation(angle);
		SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(newB);
	}
}

void TwoFace::HandleBehaviour()
{
	float elapsed = behaviourClock.getElapsedTime().asSeconds();
	if (elapsed < 3.0f)
	{
		SpiralShot();
	}
	if (elapsed > 5.0f && !hasCrossShot)
	{
		CrossShots();
		hasCrossShot = true;
	}
	if (elapsed > 8.0f)
	{
		if (health < maxHealth / 2)
		{
			SeekingShot();
		}
		behaviourClock.restart();
		hasCrossShot = false;
	}
}

void TwoFace::Update(float deltatime)
{
	HandleBehaviour();
}