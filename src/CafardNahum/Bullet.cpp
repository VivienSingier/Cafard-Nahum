#include "pch.h"
#include "Bullet.h"
#include "Room.h"
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
}
