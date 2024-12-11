#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "SceneManager.h"


class GameManager
{
	SceneManager* sceneManager;
	std::string gameState;
	Player* player;
	static GameManager* instance;

public:
	sf::RenderWindow window;

	GameManager();
	static GameManager* getInstance();
	void Init();
	void Run();

};

