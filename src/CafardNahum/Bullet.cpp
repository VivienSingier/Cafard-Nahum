#include "pch.h"
#include "Bullet.h"
#include "Room.h"
#include "Entity.h"
#include "Enemy.h"
#include "StaticObject.h"
#include "SceneManager.h"

Bullet::Bullet(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed) : 
	Entity::Entity(texture, position, scale),
	Movable::Movable(cSpeed)
{

}

void Bullet::HandleCollisions()
{
	std::vector <StaticObject*> statics = SceneManager::GetInstance()->GetCurrentScene()->GetStatics();

	for (int i = 0; i < statics.size(); i++)
	{
		if (!statics[i]->GetIsWalkable())
		{
			for (int j = 0; j < colliders.size(); j++)
			{
				if (colliders[j]->GetCollisionWithRect(statics[i]->collisionRect))
				{
					needsToBeDestroyed = true;
				}
			}
		}
	}

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
