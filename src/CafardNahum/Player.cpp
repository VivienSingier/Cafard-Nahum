#include "pch.h"
#include "Player.h"
#include "Weapon.h"
#include "Bullet.h"
#include "GameManager.h"
#include "RedLaser.h"
#include <iostream>

Player::Player(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f cSpeed) :
    Entity::Entity(path, textureRect, position, scale),
    Movable::Movable(cSpeed),
    Alive::Alive(cHealth),
    ColliderSphere::ColliderSphere()
{
    changeWeapon = false;
    isShooting = false;
}

void Player::Update(float deltatime)
{
    Move(deltatime);
    WeaponChange(holdWeapon, secondaryWeapon);
    Shoot(SceneManager::getInstance()->GetCurrentScene()->PlayerProjectiles);
}


void Player::Move(float deltatime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        move(-speed.x * deltatime, -speed.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        move(-speed.x, speed.y * deltatime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        move(speed.x * deltatime, speed.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        move(speed.x, speed.y * deltatime);
    }
}

void Player::GetShotAngle()
{
    sf::RenderWindow* window = &GameManager::getInstance()->window;
    float mousePositionX = sf::Mouse::getPosition(*window).x;
    float mousePositionY = sf::Mouse::getPosition(*window).y;
    float playerPositionX = sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
    float playerPositionY = sprite.getPosition().y + sprite.getGlobalBounds().height / 2;

    sf::Vector2f vector = sf::Vector2f(mousePositionX - playerPositionX, mousePositionY - playerPositionY);
    float vectorNorm = sqrt(vector.x * vector.x + vector.y * vector.y);
    UnitVector = sf::Vector2f(vector.x / vectorNorm, vector.y / vectorNorm);

}

void Player::WeaponChange(Weapon* holdWeapon, Weapon* secondaryWeapon)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && changeWeapon == false)
    {
        Weapon* weaponChange = holdWeapon;
        holdWeapon = secondaryWeapon;
        secondaryWeapon = weaponChange;
        std::cout << "Arme Change\n";

        changeWeapon = true;
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        changeWeapon = false;
    }
}

void Player::Shoot(std::vector <Bullet*> PlayerProjectiles)
{

    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) )
    {
        static sf::Clock shootClock;

        if (shootClock.getElapsedTime().asSeconds() >= 1.0f)
        {
            RedLaser* newBullet = new RedLaser("../../../res/Bullet/RedLaser.png", sf::IntRect(1, 1, 17, 10), sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y), sf::Vector2f(1, 1), sf::Vector2f(UnitVector));

            PlayerProjectiles.push_back(newBullet);
            std::cout << "Damage : " << newBullet->damage << std::endl;

            shootClock.restart();
        }
        else if (isShooting == false)
        {
            RedLaser* newBullet = new RedLaser("../../../res/Bullet/RedLaser.png", sf::IntRect(1, 1, 17, 10), sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y), sf::Vector2f(1, 1), sf::Vector2f(UnitVector));
            PlayerProjectiles.push_back(newBullet);
            std::cout << "Damage1 : " << newBullet->damage << std::endl;

            isShooting = true;
            shootClock.restart();
        }
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        isShooting = false;
    }
}