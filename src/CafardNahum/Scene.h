#pragma once
#include "Entity.h"
#include <vector>

class Player;
class Room;
class Corridoor;
class StaticObject;

class Scene : public sf::Drawable
{
public:
	std::vector <Entity*> entities;
	std::vector <Room*> rooms;
	std::vector <Corridoor*> corridoors;

public:
	Scene();
	void Init();
	std::vector <StaticObject*> GetStatics();
	void AddPlayer(Player* player);
	void Update(float deltatime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

