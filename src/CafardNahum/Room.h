#pragma once
#include "Entity.h"
#include "StaticObject.h"
#include <vector>

class Room : sf::Drawable
{
	std::vector <StaticObject*> objects;

public:
	Room();
	void Init(std::vector <Entity*>* LevelEntities);
	void Draw();
};

