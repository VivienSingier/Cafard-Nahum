#include "pch.h"
#include "Level.h"
#include "Room.h"
#include "VerticalCorridoor.h"
#include "HorizontalCorridoor.h"

Level::Level() : Scene()
{
	Room* Room1 = new Room(150, 200, 1);
	rooms.push_back(Room1);

	HorizontalCorridoor* Corr1 = new HorizontalCorridoor(544 + 150, 260 + 100);
	corridoors.push_back(Corr1);

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
}