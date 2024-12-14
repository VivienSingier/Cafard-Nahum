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
	static GameManager* instance;
	sf::View view;

public:
	sf::RenderWindow window;
	Player* player;

	GameManager();
	static GameManager* getInstance();
	Player* GetPlayer();
	void Init();
	void Run();

};

