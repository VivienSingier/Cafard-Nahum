#pragma once
#include "Entity.h"
#include "StaticObject.h"
#include <vector>

class Corridoor : sf::Drawable
{
	std::vector <StaticObject*> objects;

public:
	void Init(std::vector <Entity*>* LevelEntities);
	void Draw();
};
