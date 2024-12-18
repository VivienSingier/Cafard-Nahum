#include "pch.h"
#include "TwoFace.h"
#include "Ressources.h"
#include "TwoFaceSpiral.h"
#include "TwoFaceCross1.h"
#include "TwoFaceSeeking.h"
#include "SceneManager.h"
#include "Room.h"
#include <iostream>

TwoFace::TwoFace(sf::Vector2f position) :
	Boss::Boss(&StaticTextures::GetInstance()->Boss["TwoFace"], position, sf::Vector2f(2, 2), sf::Vector2f(1, 1), 200)
{
	this->setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);

	c1 = new ColliderSphere(64, position.x, position.y);
	mainColliders.push_back(c1);

	behaviourClock.restart();
	spiralClock.restart();
	hasCrossShot = true;

	spiralAngle = 0;
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
	float angle = 0;
	float radians = 3.1415926536 / 180 * angle;
	float x = 1.f * cos(radians);
	float y = -1.f * -sin(radians);

	TwoFaceSeeking* newB = new TwoFaceSeeking(getPosition().x, getPosition().y, sf::Vector2f(x, y));
	newB->setRotation(angle);
	SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(newB);

	float angle2 = 180;
	float radians2 = 3.1415926536 / 180 * angle2;
	float x2 = 1.f * cos(radians2);
	float y2 = -1.f * -sin(radians2);

	TwoFaceSeeking* newB2 = new TwoFaceSeeking(getPosition().x, getPosition().y, sf::Vector2f(x2, y2));
	newB2->setRotation(angle2);
	SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->EnemyProjectiles.push_back(newB2);
}

void TwoFace::CrossShots()
{
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
	if (health == 0)
	{
		needsToBeDestroyed = true;
	}
}

void TwoFace::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Boss::draw(target, states);
	target.draw(c1->sphere);
}