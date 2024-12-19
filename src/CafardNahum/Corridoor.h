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

public:
	sf::Vector2f pos;
	int width;
	int height;

public:
	Corridoor(float x, float y);
	virtual void Init();
	std::vector <StaticObject*> GetStatics();
	void AddWall(int x, int y);
	void AddFloor(int x, int y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawForeground(sf::RenderTarget& target, sf::RenderStates states) const;
};

