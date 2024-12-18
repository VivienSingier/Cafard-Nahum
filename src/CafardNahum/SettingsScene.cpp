#include "pch.h"
#include "SettingsScene.h"
#include "Ressources.h"
#include "StartMenu.h"
#include <string>

SettingsScene::SettingsScene(Scene* currentScene) : Scene()
{
	activeScene = currentScene;

	text = StaticTextures::GetInstance()->Text1;

	settingsText.setFont(text);
	settingsText.setString("Settings :\n\n"
		"- Movement : ZQSD\n"
		"- Shoot : Left Click\n"
		"- Swap Weapon : E\n"
		"- Rules : Your objective is to kill TwoFace and his army of roach.\n");
	settingsText.setCharacterSize(20);
	settingsText.setFillColor(sf::Color::White);
	settingsText.setPosition(520,200);

	backButton.setSize(sf::Vector2f(100, 40));
	backButton.setPosition(10, 670);
	backButton.setFillColor(sf::Color::Cyan);

	backText.setFont(text);
	backText.setString("Back");
	backText.setCharacterSize(20);
	backText.setFillColor(sf::Color::White);
	backText.setPosition(30, 680);
}

bool SettingsScene::IsMouseInside(sf::RectangleShape& button, sf::RenderWindow& window)
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

void SettingsScene::HandleInput(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (IsMouseInside(backButton, window))
		{
			activeScene = new StartMenu(activeScene);
		}

	}
}
