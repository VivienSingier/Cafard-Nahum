#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>

class ColliderRect;
class StaticObject;
class Door;
class Entity;
class Enemy;

class Room : public sf::Drawable
{
	ColliderRect* roomCollider;
	int index;
	int size;

public:
	sf::Vector2f pos;
	int width;
	int height;

public:
	std::vector <StaticObject*> backgroundObjects;
	std::vector <StaticObject*> objects;
	std::vector <StaticObject*> forwardObjects;

	std::vector <Door*> doors;
	std::vector <Enemy*> Enemies;
	std::vector <Entity*> EnemyProjectiles;

	Room(float x, float y, int index);
	void AddWall(int x, int y);
	void AddFloor(int x, int y);
	void AddDoor(int x, int y);
	void AddPoisonRoach(int x, int y);
	std::vector <StaticObject*> GetStatics();
	std::vector <Enemy*> GetEnemies();
	std::vector <Entity*> GetEnemyProjectiles();
	bool GetDoorStatus();
	void CloseDoors();
	void OpenDoors();
	void Init();
	void Update(float deltatime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawForeground(sf::RenderTarget& target, sf::RenderStates states) const;
	
};

