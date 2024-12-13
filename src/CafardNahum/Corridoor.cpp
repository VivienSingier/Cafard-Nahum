#include "pch.h"
#include "Corridoor.h"

Corridoor::Corridoor(float x, float y)
{
	pos = sf::Vector2f(x, y);
	Init();
}

void Corridoor::Init()
{

}

void Corridoor::AddWall(float x, float y)
{
	Wall* newWall = new Wall("../../../res/imgStatic/floorTiles.png",
		sf::IntRect(96, 32, 16, 16), sf::Vector2f(pos.x + 32.f * x, (pos.y - 16) + 32.f * y),
		sf::Vector2f(2.f, 2.f));

	HalfWall* newHalfWall = new HalfWall("../../../res/imgStatic/floorTiles.png",
		sf::IntRect(96, 48, 16, 16), sf::Vector2f(pos.x + 32.f * x, (pos.y + 16) + 32.f * y),
		sf::Vector2f(2.f, 2.f));

	if (y == 6)
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

void Corridoor::AddFloor(float x, float y)
{
	Floor* newFloor = new Floor("../../../res/imgStatic/floorTiles.png",
		sf::IntRect(0, 112, 16, 16), sf::Vector2f(pos.x + 32.f * x, pos.y + 32.f * y),
		sf::Vector2f(2.f, 2.f));
	backgroundObjects.push_back(newFloor);
}

void Corridoor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < backgroundObjects.size(); i++)
	{
		target.draw(*(backgroundObjects[i]));
	}
	for (int i = 0; i < objects.size(); i++)
	{
		target.draw(*(objects[i]));
	}
}

void Corridoor::drawForeground(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < forwardObjects.size(); i++)
	{
		target.draw(*(forwardObjects[i]));
	}
}