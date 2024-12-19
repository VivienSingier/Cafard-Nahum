#pragma once
#include "Entity.h"
#include <vector>

class Player;
class Room;
class Corridoor;
class StaticObject;

class Scene : public sf::Drawable
{
	Room* currentRoom;
public:
	std::vector <Entity*> entities;
	std::vector <Room*> rooms;
	std::vector <Corridoor*> corridoors;

	sf::View* view;


public:
	Scene();
	void Init();
	std::vector <StaticObject*> GetStatics();
	Room* GetCurrentRoom();
	void SetCurrentRoom(Room* room);
	void AddPlayer(Player* player);
	virtual void Update(float deltatime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

