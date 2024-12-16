#include "pch.h"
#include "GameManager.h"
#include "Player.h"
#include "PoisonRoach.h"
#include <random>

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	player = new Player("../../../res/Player/PlayerSpriteSheet.png", sf::IntRect(8, 7, 11, 21), sf::Vector2f(50.f, 50.f), sf::Vector2f(2.f, 2.f), 10, sf::Vector2f(0.20f, 0.20f));
	enemy = new PoisonRoach("../../../res/Enemy/BaseCockRoach.png", sf::IntRect(119, 119, 35, 35), sf::Vector2f(0.f, 0.f), sf::Vector2f(1.5f, 1.5f), 10, sf::Vector2f(100.f, 100.f));
	Init();
}

GameManager* GameManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new GameManager();
    }
    return instance;
}

Player* GameManager::GetPlayer()
{
	return player;
}

void GameManager::Init()
{
    window.create(sf::VideoMode(1080, 720), "Cafard Nahum");
    sceneManager = new SceneManager();
	sceneManager->GetCurrentScene()->AddPlayer(player);
	sceneManager->GetCurrentScene()->AddEnemy(enemy);


	srand(time(NULL));
	/*MapPath::Init();*/
	//StaticSpriteRect::Init();
}

void GameManager::Run()
{
	sf::Clock c;
	while (window.isOpen())
	{
		sf::Time elapsed = c.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Scene* currentScene = sceneManager->GetCurrentScene();
		sceneManager->Update(elapsed.asSeconds());

		window.clear(sf::Color::Black);
		window.draw(*currentScene);
		window.display();
	}
}