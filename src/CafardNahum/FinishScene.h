#pragma once
#include "Scene.h"

class Player;

class FinishScene : public Scene
{
	sf::Sprite MainMenuButton;
	sf::Texture MainMenuTexture;
	sf::Sprite RestartButton;
	sf::Texture RestartTexture;
	sf::Sprite QuitButton;
	sf::Texture QuitTexture;

public:
	FinishScene();
	bool IsMouseInside(sf::Sprite& button, sf::RenderWindow& window);
	void HandleInput(sf::RenderWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Update(float deltatime) override;
	
};

