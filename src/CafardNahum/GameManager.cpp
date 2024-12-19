#include "pch.h"
#include "GameManager.h"
#include <random>

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{

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
	view = sf::View(sf::FloatRect(540.f, 360.f, 1080.f, 720.f));
	view.zoom(0.7);
	window.setView(view);

	player = new Player( sf::Vector2f(300.f, 400.f), sf::Vector2f(2.f, 2.f), 10, 
		sf::Vector2f(200.f, 200.f));
	view.setCenter(player->getPosition());

	sceneManager = SceneManager::GetInstance();
	sceneManager->GetCurrentScene()->AddPlayer(player);

	srand(time(NULL));
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

		view.setCenter(player->getPosition());

		window.setView(view);
		window.clear(sf::Color::Black);
		window.draw(*currentScene);
		window.display();
	}
}

