#include "pch.h"
#include "Enemy.h"
#include "GameManager.h"

Enemy::Enemy(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f speed) :
	Entity::Entity(path, textureRect, position, scale),
	Movable::Movable(speed),
	Alive::Alive(cHealth),
	ColliderSphere::ColliderSphere()
{

}

void Enemy::Update(float deltatime)
{
	for (int i = 0 ; i<enemy.size(); i++)
	{
		enemy[i]->Update(deltatime);
	}
}

