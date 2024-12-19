#pragma once
#include "Scene.h"

class Player; 

class Victory : public Scene
{
    sf::Sprite MainMenuButton;
    sf::Texture MainMenuTexture;
    sf::Texture MainMenuTexture2;

    sf::Sprite RestartButton;
    sf::Texture RestartTexture;
    sf::Texture RestartTexture2;

    sf::Sprite QuitButton;
    sf::Texture QuitTexture;
    sf::Texture QuitTexture2;

    sf::Sprite victory;
    sf::Texture Victorytexture;

public:
    Victory();
    bool IsMouseInside(sf::Sprite& button, sf::RenderWindow& window);
    void HandleInput(sf::RenderWindow& window);
    void Update(float deltatime) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};

