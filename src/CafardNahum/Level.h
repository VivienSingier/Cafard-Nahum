#pragma once
#include "Scene.h"
#include "Room.h"
#include "Corridoor.h"
#include "Player.h"


class Level : public Scene
{
	std::vector <Room*> rooms;
	std::vector <Corridoor*> corridoors;

public:
	void AddPlayer(Player* player);
};

