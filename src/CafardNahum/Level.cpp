#include "pch.h"
#include "Level.h"

Level::Level() : Scene()
{
	Room* newRoom = new Room(&entities, 100, 100);
	rooms.push_back(newRoom);

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