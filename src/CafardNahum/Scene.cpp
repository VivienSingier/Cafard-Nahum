#include "pch.h"
#include "Scene.h"
#include "Player.h"
#include "StaticObject.h"
#include "Room.h"
#include "Corridoor.h"

Scene::Scene()
{
	
}

std::vector <StaticObject*> Scene::GetStatics()
{
	std::vector <StaticObject*> total;
	for (int i = 0; i < rooms.size(); i++)
	{
		std::vector <StaticObject*> tempV = rooms[i]->GetStatics();
		total.insert(total.end(), tempV.begin(), tempV.end());
	}
	for (int i = 0; i < corridoors.size(); i++)
	{
		std::vector <StaticObject*> tempV = corridoors[i]->GetStatics();
		total.insert(total.end(), tempV.begin(), tempV.end());
	}
	return total;
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
	for (int i = 0; i < rooms.size(); i++)
	{
		rooms[i]->Update(deltatime);
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < entities.size(); i++)
	{
		target.draw(*(entities[i]));
	}
}