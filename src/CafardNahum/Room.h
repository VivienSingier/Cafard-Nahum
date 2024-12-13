#pragma once
#include "Entity.h"
#include "HalfWall.h"

#include <vector>
#include <fstream>
#include <string>

class StaticObject;

class Room : public sf::Drawable
{

	sf::Vector2f pos;
	int index;

public:
	std::vector <StaticObject*> backgroundObjects;
	std::vector <StaticObject*> objects;
	std::vector <StaticObject*> forwardObjects;

	Room(float x, float y, int index);
	void AddWall(float x, float y);
	void AddFloor(float x, float y);
	void AddDoor(float x, float y);
	std::vector <StaticObject*> GetStatics();
	void Init();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawForeground(sf::RenderTarget& target, sf::RenderStates states) const;
};

