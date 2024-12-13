#include "pch.h"
#include "Scene.h"
#include "Player.h"

Scene::Scene()
{
	
}

void Scene::AddPlayer(Player* player)
{
	entities.push_back(player);
}

void Scene::Update(float deltatime)
{
	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->Update(deltatime);
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < entities.size(); i++)
	{
		target.draw(*(entities[i]));
	}
}