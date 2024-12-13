#pragma once
#include "Entity.h"
#include "StaticObject.h"
#include "Wall.h"
#include "HalfWall.h"
#include "Floor.h"
#include <vector>

class Corridoor : public sf::Drawable
{
	std::vector <StaticObject*> backgroundObjects;
	std::vector <StaticObject*> objects;
	std::vector <StaticObject*> forwardObjects;

	sf::Vector2f pos;

public:
	Corridoor(float x, float y);
	virtual void Init();
	void AddWall(float x, float y);
	void AddFloor(float x, float y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawForeground(sf::RenderTarget& target, sf::RenderStates states) const;
};

