#pragma once
#include "Entity.h"
#include "HalfWall.h"

#include <vector>
#include <fstream>
#include <string>

class StaticObject;

class Room : public sf::Drawable
{
	std::vector <StaticObject*> forwardObjects;
	std::vector <StaticObject*> objects;
	std::vector <StaticObject*> backgroundObjects;

	sf::Vector2f pos;

public:
	Room(std::vector <Entity*>* LevelEntities, float x, float y);
	void AddWall(float x, float y);
	void AddFloor(float x, float y);
	void AddDoor(float x, float y);
	void Init(std::vector <Entity*>* LevelEntities);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

