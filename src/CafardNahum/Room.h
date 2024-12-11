#pragma once
#include "Entity.h"
#include "StaticObject.h"
#include "Wall.h"
#include "Floor.h"
#include "HalfWall.h"

#include <vector>
#include <fstream>
#include <string>

class Room : public sf::Drawable
{
	std::vector <StaticObject*> forwardObjects;
	std::vector <StaticObject*> objects;

	sf::Vector2f pos;

public:
	Room(std::vector <Entity*>* LevelEntities, float x, float y);
	void AddWall(float x, float y);
	void AddFloor(float x, float y);
	void Init(std::vector <Entity*>* LevelEntities);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

