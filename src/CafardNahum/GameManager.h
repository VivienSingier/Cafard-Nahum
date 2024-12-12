#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "SceneManager.h"


class GameManager
{
	SceneManager* sceneManager;
	sf::RenderWindow window;
	std::string gameState;
	static GameManager* instance;

public:
	Player* player;
	GameManager();
	static GameManager* getInstance();
	void Init();
	void Run();

};

