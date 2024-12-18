#pragma once
#include "Scene.h"

class StartMenu : public Scene
{
	sf::RectangleShape playButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape quitButton;
	sf::Text playText;
	sf::Text settingsText;
	sf::Text quitText;
	sf::Font text;

	Scene* currentScene;

public :
	StartMenu(Scene* activeScene );
	bool IsMouseInside(sf::RectangleShape& button, sf::RenderWindow& window);
	void ShowSettings();
	void HandleInput(sf::RenderWindow& window);
};

