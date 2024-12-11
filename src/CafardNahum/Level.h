#pragma once
#include "Scene.h"
#include "Room.h"
#include "VerticalCorridoor.h"
#include "HorizontalCorridoor.h"
#include "Player.h"


class Level : public Scene
{
	std::vector <Room*> rooms;
	std::vector <Corridoor*> corridoors;

public:
	Level();
	void AddPlayer(Player* player);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

