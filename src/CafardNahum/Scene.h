#pragma once
#include "Entity.h"
#include <vector>

class Scene : public sf::Drawable
{
	std::vector <Entity*> entities;

public:
	Scene();
	void Init();
	void UpdateEntities();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

