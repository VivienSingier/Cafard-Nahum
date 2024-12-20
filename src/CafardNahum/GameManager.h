#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "SceneManager.h"


class GameManager
{
	SceneManager* sceneManager;
	static GameManager* instance;

public:
	sf::RenderWindow window;
	Player* player;

	GameManager();
	static GameManager* getInstance();
	Player* GetPlayer();
	void Init();
	void Run();

};

