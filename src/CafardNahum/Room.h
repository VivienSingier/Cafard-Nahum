#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>

class ColliderRect;
class StaticObject;
class Door;
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

	std::vector <Door*> doors;
	std::vector <Entity*> Enemies;
	std::vector <Entity*> EnemyProjectiles;

	Room(float x, float y, int index);
	void AddWall(float x, float y);
	void AddFloor(float x, float y);
	void AddDoor(float x, float y);
	std::vector <StaticObject*> GetStatics();
	std::vector <Entity*> GetEnemies();
	std::vector <Entity*> GetEnemyProjectiles();
	bool GetDoorStatus();
	void CloseDoors();
	void OpenDoors();
	void Init();
	void Update(float deltatime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawForeground(sf::RenderTarget& target, sf::RenderStates states) const;
};

