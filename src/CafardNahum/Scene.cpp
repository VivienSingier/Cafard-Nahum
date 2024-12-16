#include "pch.h"
#include "Scene.h"
#include "Player.h"
#include "StaticObject.h"
#include "Room.h"
#include "Corridoor.h"

#include <iostream>

Scene::Scene()
{
	currentRoom = nullptr;
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

Room* Scene::GetCurrentRoom()
{
	return currentRoom;
}

void Scene::SetCurrentRoom(Room* room)
{
	currentRoom = room;
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
	entities.erase(std::remove_if(entities.begin(), entities.end(),
		[](Entity* e) {
			bool d = e->GetNeedsToBeDestroyed();
			if (d) {
				delete e;
			}
			return d;
		}),
		entities.end());
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < entities.size(); i++)
	{
		target.draw(*(entities[i]));
	}
}