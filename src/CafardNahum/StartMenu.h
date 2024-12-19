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


public :
	StartMenu();
	bool IsMouseInside(sf::RectangleShape& button, sf::RenderWindow& window);
	void ShowSettings();
	void HandleInput(sf::RenderWindow& window);
	void Update(float deltatime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

