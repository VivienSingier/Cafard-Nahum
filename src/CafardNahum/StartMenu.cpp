#include "pch.h"
#include "StartMenu.h"
#include "Ressources.h"
#include "SettingsScene.h"
#include "GameManager.h"
#include <iostream>
#include <string>

StartMenu::StartMenu() :
	Scene::Scene()
{
	
	view = new sf::View(sf::FloatRect(0.f, 0.f, 1080.f, 720.f));

	PlayTexture = StaticTextures::GetInstance()->PlayButton;
	SettingsTexture = StaticTextures::GetInstance()->SettingsButton;
	QuitTexture = StaticTextures::GetInstance()->QuitButton;

	playButton.setTexture(PlayTexture);
	playButton.setScale(1,1);
	playButton.setPosition(440, 300);

	settingsButton.setTexture(SettingsTexture);
	settingsButton.setPosition(440, 450);
	settingsButton.setScale(1, 1);

	quitButton.setTexture(QuitTexture);
	quitButton.setPosition(440 , 600);
	quitButton.setScale(1,1);
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
}

void StartMenu::HandleInput(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
	{
		if(IsMouseInside(playButton,window))
		{
			/*lancer le jeu*/
		}
		if(IsMouseInside(settingsButton, window))
		{
			ShowSettings();
		}
		if(IsMouseInside(quitButton, window))
		{
			std::cout << "nik tes morts " << std::endl;
			window.close();
		}
	}
	std::cout << sf::Mouse::getPosition(window).x << " | " << sf::Mouse::getPosition(window).y << std::endl;
}

void StartMenu::Update(float deltatime)
{
	HandleInput(GameManager::getInstance()->window);
}

void StartMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(playButton);

	target.draw(settingsButton);

	target.draw(quitButton);
}