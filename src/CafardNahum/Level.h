#pragma once
#include "Scene.h"
#include "Player.h"

class Room;
class Corridoor;

class Level : public Scene
{
	std::vector <Room*> rooms;
	std::vector <Corridoor*> corridoors;

public:
	Level();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

