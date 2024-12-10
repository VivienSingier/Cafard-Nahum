#pragma once
#include "Entity.h"
#include <vector>

class Scene : sf::Drawable
{
	std::vector <Entity*> entities;

public:
	void Init();
	void UpdateEntities();
	void Draw();
};

