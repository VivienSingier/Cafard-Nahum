#pragma once
#include "Scene.h"

class StartMenu;

class SettingsScene : public Scene
{
	sf::Sprite backButton;
	sf::Texture BackButton;
	sf::Texture BackButton2;
	sf::Font text;
	sf::Text settingsText;

public:
	SettingsScene();
	bool IsMouseInside(sf::Sprite& button, sf::RenderWindow& window);
	void HandleInput(sf::RenderWindow& window);
	void Update(float deltatime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

}; 

