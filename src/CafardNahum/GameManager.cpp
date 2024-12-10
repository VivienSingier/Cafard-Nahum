#include "pch.h"
#include "GameManager.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
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

void GameManager::Init()
{
    window.create(sf::VideoMode(1080, 720), "Cafard Nahum");
    sceneManager = new SceneManager();
}

void GameManager::Run()
{
	sf::Clock c;
	while (window.isOpen())
	{
		float deltaTime = c.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Scene* currentScene = sceneManager->GetCurrentScene();

		window.clear(sf::Color::Black);
		window.draw(*currentScene);
		window.display();
	}
}