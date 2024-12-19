#include "pch.h"
#include "Level.h"
#include "Room.h"
#include "VerticalCorridoor.h"
#include "HorizontalCorridoor.h"
#include "PoisonRoach.h"
#include "GameManager.h"
#include "TwoFace.h"

Level::Level() : Scene()
{
	Room* Room1 = new Room(150, 200, 1);
	rooms.push_back(Room1);

	HorizontalCorridoor* Corr1 = new HorizontalCorridoor(Room1->pos.x + Room1->width, 360);
	corridoors.push_back(Corr1);

	Room* Room2 = new Room(Corr1->pos.x + Corr1->width, 200, 2);
	rooms.push_back(Room2);

	HorizontalCorridoor* Corr2 = new HorizontalCorridoor(Room2->pos.x + Room2->width, 360);
	corridoors.push_back(Corr2);

	Room* Room3 = new Room(Corr2->pos.x + Corr2->width, 200, 3);
	rooms.push_back(Room3);

	HorizontalCorridoor* Corr3 = new HorizontalCorridoor(Room3->pos.x + Room3->width, 360);
	corridoors.push_back(Corr3);

	Room* Room4 = new Room(Corr3->pos.x + Corr3->width, 200, 4);
	rooms.push_back(Room4);

	HorizontalCorridoor* Corr4 = new HorizontalCorridoor(Room4->pos.x + Room4->width, 360);
	corridoors.push_back(Corr4);

	Room* Room5 = new Room(Corr4->pos.x + Corr4->width, 104, 5);
	rooms.push_back(Room5);

	tFace = new TwoFace(sf::Vector2f(Room5->pos.x + Room5->width / 2, Room5->pos.y + Room5->height/2 - 80));
	Room5->Enemies.push_back(tFace);
	isTfaceAlive = true;

	view = new sf::View(sf::FloatRect(540.f, 360.f, 1080.f, 720.f));
	view->zoom(0.7);

}

void Level::Update(float deltatime)
{
	Scene::Update(deltatime);
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < rooms.size(); i++)
	{
		target.draw(*(rooms[i]));
	}
	for (int i = 0; i < corridoors.size(); i++)
	{
		target.draw(*(corridoors[i]));
	}
	Scene::draw(target, states);
	for (int i = 0; i < rooms.size(); i++)
	{
		rooms[i]->drawForeground(target, states);
	}
	for (int i = 0; i < corridoors.size(); i++)
	{
		corridoors[i]->drawForeground(target, states);
	}

	GameManager::getInstance()->GetPlayer()->drawHealthBar(target, states);
	if (rooms[4]->Enemies.size() > 0)
	{
		tFace->drawHealthBar(target, states);
	}
}