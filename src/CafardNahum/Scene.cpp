#include "pch.h"
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

Scene::Scene()
{
	
}

void Scene::AddPlayer(Player* player)
{
	entities.push_back(player);
}

void Scene::AddEnemy(Enemy* enemy)
{
	entities.push_back(enemy);
}


void Scene::Update(float deltatime)
{
	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->Update(deltatime);
	}
	for (int i = 0; i < PlayerProjectiles.size(); i++)
	{
		PlayerProjectiles[i]->Update(deltatime);
	}
	for (int i = 0; i < EnemyProjectiles.size(); i++)
	{
		EnemyProjectiles[i]->Update(deltatime);
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < entities.size(); i++)
	{
		target.draw(*(entities[i]));
	}
	for (int i = 0; i < PlayerProjectiles.size(); i++)
	{
		target.draw(*(PlayerProjectiles[i]));
	}
	for (int i = 0; i < EnemyProjectiles.size(); i++)
	{
		target.draw(*(EnemyProjectiles[i]));
	}
}



