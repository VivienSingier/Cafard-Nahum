#include "pch.h"
#include "Level.h"

Level::Level() : Scene()
{
	Room* newRoom = new Room(&entities);
	rooms.push_back(newRoom);
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Scene::draw(target, states);
	for (int i = 0; i < rooms.size(); i++)
	{
		target.draw(*(rooms[i]));
	}
}

