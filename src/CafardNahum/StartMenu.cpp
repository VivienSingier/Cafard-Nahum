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

	text = StaticTextures::GetInstance()->Text1;

	playButton.setSize(sf::Vector2f( 200, 50));
	playButton.setPosition(440, 300);
	playButton.setFillColor(sf::Color::Blue);

	playText.setFont(text);
	playText.setString("Play");
	playText.setCharacterSize(20);
	playText.setFillColor(sf::Color::White);
	playText.setPosition(500,310);

	settingsButton.setSize(sf::Vector2f(200, 50));
	settingsButton.setPosition(440, 450);
	settingsButton.setFillColor(sf::Color::Blue);

	settingsText.setFont(text);
	settingsText.setString("Settings");
	settingsText.setCharacterSize(20);
	settingsText.setFillColor(sf::Color::White);
	settingsText.setPosition(500, 460);

	quitButton.setSize(sf::Vector2f(200, 50));
	quitButton.setPosition(440 , 600);
	quitButton.setFillColor(sf::Color::Blue);

	quitText.setFont(text);
	quitText.setString("Quit");
	quitText.setCharacterSize(20);
	quitText.setFillColor(sf::Color::White);
	quitText.setPosition(500, 610);
}

bool StartMenu::IsMouseInside(sf::RectangleShape& button, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f buttonPos = button.getPosition();
	sf::Vector2f buttonSize = button.getSize();

	if (mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + buttonSize.x &&
		mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + buttonSize.y)
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
	target.draw(playText);

	target.draw(settingsButton);
	target.draw(settingsText);

	target.draw(quitButton);
	target.draw(quitText);
}