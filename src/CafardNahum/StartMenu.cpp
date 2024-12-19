#include "pch.h"
#include "StartMenu.h"
#include "SceneManager.h"
#include "Ressources.h"
#include "SettingsScene.h"
#include "GameManager.h"
#include <iostream>
#include <string>

StartMenu::StartMenu() :
	Scene::Scene()
{
	
	view = new sf::View(sf::FloatRect(0.f, 0.f, 1080.f, 720.f));

	menuTexture = StaticTextures::GetInstance()->MenuTexture;
	PlayTexture = StaticTextures::GetInstance()->PlayButton;
	SettingsTexture = StaticTextures::GetInstance()->SettingsButton;
	QuitTexture = StaticTextures::GetInstance()->QuitButton;
	PlayTexture2 = StaticTextures::GetInstance()->PlayButton2;
	SettingsTexture2 = StaticTextures::GetInstance()->SettingsButton2;
	QuitTexture2 = StaticTextures::GetInstance()->QuitButton2;

	Menu.setTexture(menuTexture);
	Menu.setPosition(0, 0);
	Menu.setScale(1, 1);

	playButton.setTexture(PlayTexture);
	playButton.setScale(2,2);
	playButton.setPosition(467, 300);

	settingsButton.setTexture(SettingsTexture);
	settingsButton.setPosition(467, 450);
	settingsButton.setScale(2, 2);

	quitButton.setTexture(QuitTexture);
	quitButton.setPosition(467, 570);
	quitButton.setScale(2,2);
}

bool StartMenu::IsMouseInside(sf::Sprite& button, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f buttonPos = button.getPosition();
	float buttonSizeX = button.getGlobalBounds().width;
	float buttonSizeY = button.getGlobalBounds().height;


	if (mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + buttonSizeX &&
		mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + buttonSizeY)
	{
		return true;
	}
	else
		return false;
}

void StartMenu::ShowSettings()
{
	SceneManager::GetInstance()->SetCurrentScene("SettingsScene");
}

void StartMenu::HandleInput(sf::RenderWindow& window)
{

	if (IsMouseInside(playButton, window))
	{
		playButton.setTexture(PlayTexture2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			SceneManager::GetInstance()->SetCurrentScene("Level");
		}
	}
	else
		playButton.setTexture(PlayTexture);


	if (IsMouseInside(settingsButton, window))
	{
		settingsButton.setTexture(SettingsTexture2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			ShowSettings();
		}
	}
	else
		settingsButton.setTexture(SettingsTexture);

	if (IsMouseInside(quitButton, window))
	{
		quitButton.setTexture(QuitTexture2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			window.close();
		}
	}
	else
		quitButton.setTexture(QuitTexture);



	std::cout << sf::Mouse::getPosition(window).x << " | " << sf::Mouse::getPosition(window).y << std::endl;
}

void StartMenu::Update(float deltatime)
{
	HandleInput(GameManager::getInstance()->window);
}

void StartMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Menu);

	target.draw(playButton);

	target.draw(settingsButton);

	target.draw(quitButton);
}