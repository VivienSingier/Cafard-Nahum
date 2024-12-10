#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "SceneManager.h"


class GameManager
{
	SceneManager* CurrentScene;
	sf::RenderWindow window;
	std::string gameState;
	Player* player;

public:

	static GameManager* getInstance();
	void Init();
	void Run();

};

