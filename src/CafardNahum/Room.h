#pragma once
#include "Entity.h"
#include "StaticObject.h"
#include "Wall.h"
#include "Floor.h"

#include <vector>
#include <fstream>
#include <string>

class Room : public sf::Drawable
{
	std::vector <StaticObject*> objects;

public:
	Room(std::vector <Entity*>* LevelEntities);
	void AddWall(float x, float y);
	void AddFloor(float x, float y);
	void Init(std::vector <Entity*>* LevelEntities);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

