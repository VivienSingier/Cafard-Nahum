#include "pch.h"
#include "Player.h"

Player::Player(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f cSpeed) :
    Entity::Entity(path, textureRect, position, scale),
    Movable::Movable(cSpeed),
    Alive::Alive(cHealth),
    ColliderSphere::ColliderSphere()
{
}

void Player::Move(float deltatime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        move(0, -20.f * deltatime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        move(-20.f * deltatime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        move(0, 20.f * deltatime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        move(20.f * deltatime, 0);
    }
}

void Player::GetShotAngle()
{
    sf::RenderWindow* window = &GameManager::getInstance()->window;  
    float mousePositionX = sf::Mouse::getPosition(*window).x;
    float mousePositionY = sf::Mouse::getPosition(*window).y;
    float playerPositionX = sprite.getPosition().x;
    float playerPositionY = sprite.getPosition().y;

    sf::Vector2f vector = sf::Vector2f(mousePositionX - playerPositionX, mousePositionY - playerPositionY);
    float vectorNorm = sqrt(vector.x + vector.y);
    sf::Vector2f UnitVector = sf::Vector2f(vector.x/vectorNorm, vector.y/vectorNorm);

}

void Player::Shoot(std::vector <Bullet*> PlayerProjectiles)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){}
}