#include "pch.h"
#include "SettingsScene.h"
#include "Ressources.h"
#include "StartMenu.h"
#include "GameManager.h"
#include <string>

SettingsScene::SettingsScene() : Scene()
{
	view = new sf::View(sf::FloatRect(0.f, 0.f, 1080.f, 720.f));


	BackButton = StaticTextures::GetInstance()->BackButton;
	BackButton2 = StaticTextures::GetInstance()->BackButton2;
	text = StaticTextures::GetInstance()->text;

	settingsText.setFont(text);
	settingsText.setString("Settings :\n\n\n"
		"- Movement : ZQSD\n\n"
		"- Shoot : Left Click\n\n"
		"- Swap Weapon : E\n\n"
		"- Rules : Your objective is to kill TwoFace\n          and his army of roaches.\n\n");
	settingsText.setCharacterSize(20);
	settingsText.setFillColor(sf::Color::White);
	settingsText.setPosition(300,200);

	backButton.setTexture(BackButton);
	backButton.setPosition(20, 600);
	backButton.setScale(2,2);
}

bool SettingsScene::IsMouseInside(sf::Sprite& button, sf::RenderWindow& window)
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

void SettingsScene::HandleInput(sf::RenderWindow& window)
{
	
	if (IsMouseInside(backButton, window))
	{
		backButton.setTexture(BackButton2);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			new StartMenu();
		}
	}
	else
		backButton.setTexture(BackButton);

	
}
void SettingsScene::Update(float deltatime)
{
	HandleInput(GameManager::getInstance()->window);
}

void SettingsScene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(settingsText);

	target.draw(backButton);	
}
