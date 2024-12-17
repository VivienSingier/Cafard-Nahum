#include "pch.h"
#include "Corridoor.h"
#include "Ressources.h"

Corridoor::Corridoor(float x, float y)
{
	pos = sf::Vector2f(x, y);
	Init();
}

void Corridoor::Init()
{

}

std::vector <StaticObject*> Corridoor::GetStatics()
{
	std::vector <StaticObject*> total = backgroundObjects;
	total.insert(total.end(), objects.begin(), objects.end());
	total.insert(total.end(), forwardObjects.begin(), forwardObjects.end());
	return total;
}

void Corridoor::AddWall(int x, int y)
{
	Wall* newWall = new Wall(&StaticTextures::GetInstance()->Walls["WallTop"],
		sf::Vector2f(pos.x + 32.f * x, (pos.y - 16) + 32.f * y),
		sf::Vector2f(2.f, 2.f));

	HalfWall* newHalfWall = new HalfWall(&StaticTextures::GetInstance()->Walls["WallBottom"],
		sf::Vector2f(pos.x + 32.f * x, (pos.y + 16) + 32.f * y),
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

void Corridoor::AddFloor(int x, int y)
{

	Floor* newFloor = new Floor(&StaticTextures::GetInstance()->Floors["Purple1"],
		sf::Vector2f(pos.x + 32.f * x, pos.y + 32.f * y),
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