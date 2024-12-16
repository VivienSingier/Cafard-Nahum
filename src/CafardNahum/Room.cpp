#include "pch.h"
#include "Room.h"
#include "Wall.h"
#include "Floor.h"
#include "HalfWall.h"
#include "ColliderSphere.h"
#include "ColliderRect.h"
#include "Door.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "Ressources.h"
#include <random>


Room::Room(float x, float y, int cIndex)
{
	index = cIndex;
	pos = sf::Vector2f(x, y);
	roomCollider = new ColliderRect(pos.x + 64, pos.y + 64, 32 * 13, 32 * 13);

	Init();
}

void Room::AddWall(float x, float y)
{
	Wall* newWall = new Wall("../../../res/imgStatic/floorTiles.png",
		sf::IntRect(96, 32, 16, 16), sf::Vector2f(pos.x + 32.f * x, (pos.y - 16) + 32.f * y),
		sf::Vector2f(2.f, 2.f));

	HalfWall* newHalfWall = new HalfWall("../../../res/imgStatic/floorTiles.png",
		sf::IntRect(96, 48, 16, 16), sf::Vector2f(pos.x + 32.f * x, (pos.y + 16) + 32.f * y),
		sf::Vector2f(2.f, 2.f));

	if (y > 6)
	{
		forwardObjects.push_back(newWall);
		forwardObjects.push_back(newHalfWall);
	}
	else
	{
		objects.push_back(newWall);
		objects.push_back(newHalfWall);
	}
}

void Room::AddFloor(float x, float y)
{
	Floor* newFloor = new Floor(StaticTextures::GetInstance()->Floors["Purple1"],
		sf::Vector2f(pos.x + 32.f * x, pos.y + 32.f * y),
		sf::Vector2f(2.f, 2.f));
	backgroundObjects.push_back(newFloor);
}

void Room::AddDoor(float x, float y)
{
	Door* newDoor = new Door(sf::Vector2f(pos.x + 32.f * x, pos.y + 32.f * y));
	doors.push_back(newDoor);
}

std::vector <StaticObject*> Room::GetStatics()
{
	std::vector <StaticObject*> total = backgroundObjects;
	total.insert(total.end(), objects.begin(), objects.end());
	total.insert(total.end(), forwardObjects.begin(), forwardObjects.end());
	total.insert(total.end(), doors.begin(), doors.end());
	return total;
}

std::vector <Entity*> Room::GetEnemies()
{
	return Enemies;
}

std::vector <Entity*> Room::GetEnemyProjectiles()
{
	return EnemyProjectiles;
}

bool Room::GetDoorStatus()
{
	if (doors[0]->GetIsOpen())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Room::OpenDoors()
{
	for (int i = 0; i < doors.size(); i++)
	{
		doors[i]->Open();
	}
}

void Room::CloseDoors()
{
	for (int i = 0; i < doors.size(); i++)
	{
		doors[i]->Close();
	}
}

void Room::Init()
{
	std::string path;
	switch (index)
	{
	case 1:
		path = "../../../res/Maps/Floor1/1.txt";
		break;
	case 2:
		path = "../../../res/Maps/Floor1/2.txt";
		break;
	case 3:
		path = "../../../res/Maps/Floor1/3.txt";
		break;
	}
	std::ifstream file(path);
	std::string str;
	int i = 0;
	while (std::getline(file, str))
	{
		for (int j = 0; j < 17; j++)
		{
			if (str[j] == 'W')
			{
				AddWall((float)j, (float)i);
			}
			else if (str[j] == 'F')
			{
				AddFloor((float)j, (float)i);
			}
			else if (str[j] == 'D')
			{
				AddDoor((float)j, (float)i);
			}
		}
		i++;
	}
}

void Room::Update(float deltatime)
{
	if (GetDoorStatus() && Enemies.size() > 0)
	{
		if (GameManager::getInstance()->GetPlayer()->c1->GetCollisionWithRect(roomCollider))
		{
			CloseDoors();

		}
	}
	else if (Enemies.size() == 0)
	{
		if (!GameManager::getInstance()->GetPlayer()->c1->GetCollisionWithRect(roomCollider))
		{
			OpenDoors();
		}
	}

	if (GameManager::getInstance()->GetPlayer()->c1->GetCollisionWithRect(roomCollider))
	{
		if (SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom() != this)
		{
			SceneManager::GetInstance()->GetCurrentScene()->SetCurrentRoom(this);
		}
	}

	for (int i = 0; i < Enemies.size(); i++)
	{
		Enemies[i]->Update(deltatime);
	}
	for (int i = 0; i < EnemyProjectiles.size(); i++)
	{
		EnemyProjectiles[i]->Update(deltatime);
	}
}

void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < backgroundObjects.size(); i++)
	{
		target.draw(*(backgroundObjects[i]));
	}
	for (int i = 0; i < objects.size(); i++)
	{
		target.draw(*(objects[i]));
	}
	for (int i = 0; i < doors.size(); i++)
	{
		target.draw(*(doors[i]));
	}
	for (int i = 0; i < EnemyProjectiles.size(); i++)
	{
		target.draw(*(EnemyProjectiles[i]));
	}

}

void Room::drawForeground(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < forwardObjects.size(); i++)
	{
		target.draw(*(forwardObjects[i]));
	}
}