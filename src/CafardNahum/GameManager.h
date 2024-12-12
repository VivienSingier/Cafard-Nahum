#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>

class Player;
class SceneManager;

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
	Player* GetPlayer();
	void Init();
	void Run();

};

