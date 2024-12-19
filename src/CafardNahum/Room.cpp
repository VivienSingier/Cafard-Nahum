#include "pch.h"
#include "Room.h"
#include "Wall.h"
#include "Floor.h"
#include "Enemy.h"
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
	width = 32 * size;
	height = 32 * size + 32;
}

void Room::AddWall(int x, int y)
{
	Wall* newWall = new Wall(&StaticTextures::GetInstance()->Walls["WallTop"], 
		sf::Vector2f(pos.x + 32.f * x, (pos.y - 16) + 32.f * y),
		sf::Vector2f(2.f, 2.f));

	HalfWall* newHalfWall = new HalfWall(&StaticTextures::GetInstance()->Walls["WallBottom"],
		sf::Vector2f(pos.x + 32.f * x, (pos.y + 16) + 32.f * y),
		sf::Vector2f(2.f, 2.f));

	if (y > (size / 2))
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

void Room::AddFloor(int x, int y)
{
	sf::Texture* texture;
	if (((x + y) % 2) == 0)
	{
		texture = &StaticTextures::GetInstance()->Floors["White1"];
	}
	else
	{
		texture = &StaticTextures::GetInstance()->Floors["Black1"];
	}
	Floor* newFloor = new Floor(texture,
		sf::Vector2f(pos.x + 32.f * x, pos.y + 32.f * y),
		sf::Vector2f(2.f, 2.f));
	backgroundObjects.push_back(newFloor);
}

void Room::AddDoor(int x, int y)
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

std::vector <Enemy*> Room::GetEnemies()
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
	case 4:
		path = "../../../res/Maps/Floor1/4.txt";
		break;
	case 5:
		path = "../../../res/Maps/Floor1/5.txt";
		break;
	}
	std::ifstream file(path);
	std::string str;
	int i = 0;
	while (std::getline(file, str))
	{
		size = str.size();
		for (int j = 0; j < size; j++)
		{
			if (str[j] == 'W')
			{
				AddWall((float)j, (float)i);
			}
			else if (str[j] == 'F')
			{
				AddFloor(j, i);
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
	if (GameManager::getInstance()->GetPlayer()->c1->GetCollisionWithRect(roomCollider))
	{
		if (SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom() != this)
		{
			SceneManager::GetInstance()->GetCurrentScene()->SetCurrentRoom(this);
		}
	}

	if (SceneManager::GetInstance()->GetCurrentScene()->GetCurrentRoom() == this)
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
				OpenDoors();
		}

		for (int i = 0; i < Enemies.size(); i++)
		{
			Enemies[i]->Update(deltatime);
		}
		for (int i = 0; i < EnemyProjectiles.size(); i++)
		{
			EnemyProjectiles[i]->Update(deltatime);
		}

		Enemies.erase(std::remove_if(Enemies.begin(), Enemies.end(),
			[](Enemy* e) {
				bool d = e->GetNeedsToBeDestroyed();
				if (d) {
					delete e;
				}
				return d;
			}),
			Enemies.end());

		EnemyProjectiles.erase(std::remove_if(EnemyProjectiles.begin(), EnemyProjectiles.end(),
			[](Entity* e) {
				bool d = e->GetNeedsToBeDestroyed();
				if (d) {
					delete e;
				}
				return d;
			}),
			EnemyProjectiles.end());
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
	for (int i = 0; i < Enemies.size(); i++)
	{
		target.draw(*(Enemies[i]));
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