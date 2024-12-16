#include "pch.h"
#include "Level.h"
#include "Room.h"
#include "VerticalCorridoor.h"
#include "HorizontalCorridoor.h"
#include "PoisonRoach.h"

Level::Level() : Scene()
{
	Room* Room1 = new Room(150, 200, 1);
	rooms.push_back(Room1);

	PoisonRoach* pR = new PoisonRoach(sf::Vector2f(200, 250));
	Room1->Enemies.push_back(pR);

	HorizontalCorridoor* Corr1 = new HorizontalCorridoor(694, 360);
	corridoors.push_back(Corr1);

	Room* Room2 = new Room(1174, 200, 2);
	rooms.push_back(Room2);

	HorizontalCorridoor* Corr2 = new HorizontalCorridoor(1718, 360);
	corridoors.push_back(Corr2);

	Room* Room3 = new Room(2198, 200, 2);
	rooms.push_back(Room3);

	HorizontalCorridoor* Corr3 = new HorizontalCorridoor(2742, 360);
	corridoors.push_back(Corr3);

	Room* Room4 = new Room(3222, 200, 2);
	rooms.push_back(Room4);

	HorizontalCorridoor* Corr4 = new HorizontalCorridoor(2742 + 1024, 360);
	corridoors.push_back(Corr4);

	Room* Room5 = new Room(3222 + 1024, 200, 3);
	rooms.push_back(Room5);

}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < rooms.size(); i++)
	{
		target.draw(*(rooms[i]));
	}
	for (int i = 0; i < corridoors.size(); i++)
	{
		target.draw(*(corridoors[i]));
	}
	Scene::draw(target, states);
	for (int i = 0; i < rooms.size(); i++)
	{
		rooms[i]->drawForeground(target, states);
	}
	for (int i = 0; i < corridoors.size(); i++)
	{
		corridoors[i]->drawForeground(target, states);
	}
}