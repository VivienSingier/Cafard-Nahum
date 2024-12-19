#include "pch.h"
#include "Pepper.h"
#include "ColliderSphere.h"
#include "Ressources.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "Room.h"

Pepper::Pepper(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["Pepper"],
		sf::Vector2f(x, y), sf::Vector2f(0.5, 0.5), direction)
{
	damage = 1;
	this->setOrigin(sf::Vector2f(8, 8));

	c1 = new ColliderSphere(4, x, y);
	colliders.push_back(c1);
}

void Pepper::Move(float deltatime)
{
	move(sf::Vector2f(600 * deltatime * speed.x, 600 * deltatime * speed.y));
	c1->Move(600 * deltatime * speed.x, 600 * deltatime * speed.y);
}

void Pepper::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
}

void Pepper::HandleCollisions()
{
	Bullet::HandleCollisions();
	std::vector <Enemy*> enemies = SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom()->Enemies;

	for (int i = 0; i < enemies.size(); i++)
	{
		for (int j = 0; j < colliders.size(); j++)
		{
			for (int k = 0; k < enemies[i]->mainColliders.size(); k++)
			{
				if (colliders[j]->GetCollisionWithSphere(enemies[i]->mainColliders[k]))
				{
					needsToBeDestroyed = true;
					enemies[i]->TakeDamage(damage);
				}
			}
		}
	}
}
