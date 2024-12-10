#include "pch.h"
#include "Room.h"
#include <iostream>

Room::Room(std::vector <Entity*>* LevelEntities)
{
	std::cout << "init" << std::endl;
	Init(LevelEntities);
}

void Room::AddWall(float x, float y)
{
	Wall* newWall = new Wall("../../../res/imgStatic/floorTiles.png",
		sf::IntRect(96, 32, 16, 16), sf::Vector2f(100.f + 32. * x, 100.f + 32.f * y),
		sf::Vector2f(2.f, 2.f));
	objects.push_back(newWall);
}

void Room::AddFloor(float x, float y)
{
	Floor* newFloor = new Floor("../../../res/imgStatic/floorTiles.png",
		sf::IntRect(96, 32, 16, 16), sf::Vector2f(100.f + 32. * x, 100.f + 32.f * y),
		sf::Vector2f(2.f, 2.f));
	objects.push_back(newFloor);
}

void Room::Init(std::vector <Entity*>* LevelEntities)
{
	std::ifstream file("../../../res/Maps/Floor1/1.txt");
	std::string str;
	int i = 0;
	while (std::getline(file, str))
	{
		for (int j = 0; j < 17; j++)
		{
			if (str[i] == 'W')
			{
				AddWall((float)i, (float)j);
			}
			else if (str[j] == 'F')
			{
				AddFloor((float)i, (float)j);
			}
		}
		i++;
	}
}

void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < objects.size(); i++)
	{
		target.draw(*(objects[i]));
	}
}