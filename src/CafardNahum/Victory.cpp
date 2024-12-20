#include "pch.h"
#include "Victory.h"

#include "Ressources.h"
#include "GameManager.h"
#include "SettingsScene.h"


Victory::Victory() :
    Scene()
{
    view = new sf::View(sf::FloatRect(0.f, 0.f, 1080.f, 720.f));

    MainMenuTexture = StaticTextures::GetInstance()->MainMenuButton;
    MainMenuTexture2 = StaticTextures::GetInstance()->MainMenuButton2;

    RestartTexture = StaticTextures::GetInstance()->RestartButton;
    RestartTexture2 = StaticTextures::GetInstance()->RestartButton2;

    QuitTexture = StaticTextures::GetInstance()->QuitButton;
    QuitTexture2 = StaticTextures::GetInstance()->QuitButton2;

    Victorytexture = StaticTextures::GetInstance()->Victory;

    MainMenuButton.setTexture(MainMenuTexture);
    MainMenuButton.setPosition(467, 450);
    MainMenuButton.setScale(2, 2);

    RestartButton.setTexture(RestartTexture);
    RestartButton.setPosition(467, 300);
    RestartButton.setScale(2, 2);

    QuitButton.setTexture(QuitTexture);
    QuitButton.setPosition(467, 570);
    QuitButton.setScale(2, 2);

    victory.setTexture(Victorytexture);
    victory.setPosition(367, 60);
    victory.setScale(4, 4);
}


bool Victory::IsMouseInside(sf::Sprite& button, sf::RenderWindow& window)
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
void Victory::HandleInput(sf::RenderWindow& window)
{
    if (IsMouseInside(RestartButton, window))
    {
        RestartButton.setTexture(RestartTexture2);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            SceneManager::GetInstance()->SetCurrentScene("Level");
        }
    }
    else
        RestartButton.setTexture(RestartTexture);

    if (IsMouseInside(MainMenuButton, window))
    {
        MainMenuButton.setTexture(MainMenuTexture2);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            SceneManager::GetInstance()->SetCurrentScene("StartMenu");
        }
    }
    else
        MainMenuButton.setTexture(MainMenuTexture);

    if (IsMouseInside(QuitButton, window))
    {
        QuitButton.setTexture(QuitTexture2);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            window.close();
        }
    }
    else
        QuitButton.setTexture(QuitTexture);
}

void Victory::Update(float deltatime)
{
    HandleInput(GameManager::getInstance()->window);
}

void Victory::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(victory);

    target.draw(RestartButton);

    target.draw(MainMenuButton);

    target.draw(QuitButton);
}