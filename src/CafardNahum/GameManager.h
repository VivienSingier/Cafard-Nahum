#pragma once
#include <vector>
#include "SceneManager.h"
#include <SFML/Graphics.hpp>
#include <string>


class Player;
class PoisonRoach;

class GameManager
{
	SceneManager* sceneManager;
	std::string gameState;
	static GameManager* instance;
	Player* player;
	PoisonRoach* enemy;

public:
	sf::RenderWindow window;

	GameManager();
	static GameManager* getInstance();
	Player* GetPlayer();
	void Init();
	void Run();

};

