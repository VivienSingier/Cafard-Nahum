#pragma once
#include "Entity.h"
#include "StaticObject.h"
#include <vector>

class Corridoor : sf::Drawable
{
	std::vector <StaticObject*> objects;

public:
	Corridoor();
	void Init(std::vector <Entity*>* LevelEntities);
	void Draw();
};

