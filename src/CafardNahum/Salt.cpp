#include "pch.h"
#include "Salt.h"
#include "ColliderSphere.h"
#include "Ressources.h"
#include "Enemy.h"
#include "SceneManager.h"
#include "Room.h"

Salt::Salt(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["Salt"],
		sf::Vector2f(x, y), sf::Vector2f(0.5, 0.5), direction)
{
	damage = 1;
	this->setOrigin(sf::Vector2f(8, 8));

	c1 = new ColliderSphere(4, x, y);
	colliders.push_back(c1);
}

void Salt::Move(float deltatime)
{
	move(sf::Vector2f(600 * deltatime * speed.x, 600 * deltatime * speed.y));
	c1->Move(600 * deltatime * speed.x, 600 * deltatime * speed.y);
}

void Salt::Update(float deltatime)
{
	Move(deltatime);
	HandleCollisions();
}

void Salt::HandleCollisions()
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
