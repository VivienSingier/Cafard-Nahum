#pragma once
#include "Scene.h"

class StartMenu : public Scene
{
	sf::Sprite Menu;
	sf::Sprite playButton;
	sf::Sprite settingsButton;
	sf::Sprite quitButton;
	sf::Texture menuTexture;
	sf::Texture PlayTexture;
	sf::Texture SettingsTexture;
	sf::Texture QuitTexture;
	sf::Texture PlayTexture2;
	sf::Texture SettingsTexture2;
	sf::Texture QuitTexture2;

public :
	StartMenu();
	bool IsMouseInside(sf::Sprite& button, sf::RenderWindow& window);
	void ShowSettings();
	void HandleInput(sf::RenderWindow& window);
	void Update(float deltatime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

