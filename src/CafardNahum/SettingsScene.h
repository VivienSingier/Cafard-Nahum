#pragma once
#include "Scene.h"

class StartMenu;

class SettingsScene : public Scene
{
	sf::RectangleShape backButton;
	sf::Text settingsText;
	sf::Text backText;
	sf::Font text;

public:
	SettingsScene();
	bool IsMouseInside(sf::RectangleShape& button, sf::RenderWindow& window);
	void HandleInput(sf::RenderWindow& window);
}; 

