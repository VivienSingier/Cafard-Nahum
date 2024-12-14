#pragma once

#include <vector>
#include <fstream>
#include <string>

class ColliderRect;
class StaticObject;
class Entity;

class Room : public sf::Drawable
{
	ColliderRect* roomCollider;
	sf::Vector2f pos;
	int index;

public:
	std::vector <StaticObject*> backgroundObjects;
	std::vector <StaticObject*> objects;
	std::vector <StaticObject*> forwardObjects;

	Room(float x, float y, int index);
	void AddWall(float x, float y);
	void AddFloor(float x, float y);
	void AddDoor(float x, float y);
	std::vector <StaticObject*> GetStatics();
	bool GetDoorStatus();
	void Init();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawForeground(sf::RenderTarget& target, sf::RenderStates states) const;
};

