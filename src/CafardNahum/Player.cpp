#include "pch.h"
#include "Player.h"
#include "Weapon.h"
#include "Bullet.h"
#include "SceneManager.h"
#include "ColliderSphere.h"
#include "ColliderRect.h"
#include "GameManager.h"
#include "Room.h"
#include "Wall.h"
#include "MayoBottle.h"
#include "Ressources.h"

#include <iostream>

Player::Player(sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f cSpeed) :
    Entity::Entity(&StaticTextures::GetInstance()->playerIdleCycleR[0], position, scale),
    Movable::Movable(cSpeed),
    Alive::Alive(cHealth)
{
    c1 = new ColliderSphere(15, this->getPosition().x + sprite.getGlobalBounds().width / 2, this->getPosition().y + sprite.getGlobalBounds().height / 2);
    cO = new ColliderSphere(1, this->getPosition().x + sprite.getGlobalBounds().width / 2 - 15.f, this->getPosition().y + sprite.getGlobalBounds().height / 2);
    cE = new ColliderSphere(1, this->getPosition().x + sprite.getGlobalBounds().width / 2 + 15.f, this->getPosition().y + sprite.getGlobalBounds().height / 2);
    cN = new ColliderSphere(1, this->getPosition().x + sprite.getGlobalBounds().width / 2 , this->getPosition().y + sprite.getGlobalBounds().height / 2 - 7.f);
    cS = new ColliderSphere(1, this->getPosition().x + sprite.getGlobalBounds().width / 2, this->getPosition().y + sprite.getGlobalBounds().height / 2 + 7.f);

    holdWeapon = new MayoBottle(cE->sphere.getPosition().x - 10, cE->sphere.getPosition().y + 10);
    secondaryWeapon = nullptr;
}

void Player::Update(float deltatime)
{
    HandleInput(deltatime);
    float angle = GetShotAngle();
    holdWeapon->Rotate(angle);
    Shoot();
}

void Player::Move(float x, float y)
{
    move(x, y);
    c1->Move(x, y);
    cO->Move(x, y);
    cE->Move(x, y);
    cN->Move(x, y);
    cS->Move(x, y);

    holdWeapon->Move(x, y);
}

void Player::HandleInput(float deltatime)
{
    std::vector <StaticObject*> StObj = SceneManager::GetInstance()->GetCurrentScene()->GetStatics();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        if (!CheckCollisionWall(StObj, cN))
        {
            Move(0, -speed.y * deltatime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        if (!CheckCollisionWall(StObj, cO))
        {
            Move(- speed.x * deltatime, 0);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (!CheckCollisionWall(StObj, cS))
        {
            Move(0, speed.y * deltatime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {   
        if (!CheckCollisionWall(StObj, cE))
        {
            Move(speed.x * deltatime, 0);
        }
    }
}

bool Player::CheckCollisionWall(std::vector <StaticObject*> stObjVect, ColliderSphere* sphere)
{
    for (int i = 0; i < stObjVect.size(); i++)
    {
        if (!stObjVect[i]->GetIsWalkable())
        {
            if (sphere->GetCollisionWithRect(stObjVect[i]->collisionRect))
            {
                return true;
            }
        }
    }
    return false;
}

float Player::GetShotAngle()
{
    sf::RenderWindow* window = &GameManager::getInstance()->window;

    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    sf::Vector2u playerPos = window->getSize();
    playerPos.x /= 2;
    playerPos.y /= 2;
    playerPos.x += sprite.getGlobalBounds().width / 2 + 15;
    playerPos.y += sprite.getGlobalBounds().height / 2 + 15;

    float angle = atan2(((float)mousePos.y - (float)playerPos.y), (float)mousePos.x - (float)playerPos.x);
    angle *= (180.0 / 3.141592653589793238463);

    return angle;
}

void Player::WeaponChange(Weapon* holdWeapon, Weapon* secondaryWeapon)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        Weapon* weaponChange = holdWeapon;
        holdWeapon = secondaryWeapon;
        secondaryWeapon = weaponChange;
    }
}

void Player::Shoot()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        static sf::Clock shootClock;

        if (shootClock.getElapsedTime().asSeconds() >= 0.5f)
        {
            float angle = GetShotAngle();
            holdWeapon->Shoot(angle);

            shootClock.restart();
        }
    }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Entity::draw(target, states);
    holdWeapon->draw(target, states);
}