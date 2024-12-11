#include "pch.h"
#include "Level.h"

Level::Level() : Scene()
{
	Room* newRoom = new Room(&entities, 50, 0);
	rooms.push_back(newRoom);

	VerticalCorridoor* newCorridoor = new VerticalCorridoor(700, 0);
	corridoors.push_back(newCorridoor);

	HorizontalCorridoor* newCorridoor2 = new HorizontalCorridoor(50, 550);
	corridoors.push_back(newCorridoor2);

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