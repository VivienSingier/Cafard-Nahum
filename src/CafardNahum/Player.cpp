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

Player::Player(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f cSpeed) :
    Entity::Entity(path, textureRect, position, scale),
    Movable::Movable(cSpeed),
    Alive::Alive(cHealth)
{
    c1 = new ColliderSphere(15, sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + sprite.getGlobalBounds().height / 2);
    cO = new ColliderSphere(1, sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 15.f, sprite.getPosition().y + sprite.getGlobalBounds().height / 2);
    cE = new ColliderSphere(1, sprite.getPosition().x + sprite.getGlobalBounds().width / 2 + 15.f, sprite.getPosition().y + sprite.getGlobalBounds().height / 2);
    cN = new ColliderSphere(1, sprite.getPosition().x + sprite.getGlobalBounds().width / 2 , sprite.getPosition().y + sprite.getGlobalBounds().height / 2 - 7.f);
    cS = new ColliderSphere(1, sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + sprite.getGlobalBounds().height / 2 + 7.f);
}

void Player::Update(float deltatime)
{
    Move(deltatime);
}


void Player::Move(float deltatime)
{
    std::vector <StaticObject*> StObj = SceneManager::GetInstance()->GetCurrentScene()->rooms[0]->forwardObjects;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        if (!CheckCollisionWall(StObj, cN))
        {
            move(-speed.x * deltatime, -speed.y);
            c1->Move(-speed.x * deltatime, -speed.y);
            cO->Move(-speed.x * deltatime, -speed.y);
            cE->Move(-speed.x * deltatime, -speed.y);
            cN->Move(-speed.x * deltatime, -speed.y);
            cS->Move(-speed.x * deltatime, -speed.y); 
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        if (!CheckCollisionWall(StObj, cO))
        {
            move(-speed.x, speed.y * deltatime);
            c1->Move(-speed.x, speed.y * deltatime);
            cO->Move(-speed.x, speed.y * deltatime);
            cE->Move(-speed.x, speed.y * deltatime);
            cN->Move(-speed.x, speed.y * deltatime);
            cS->Move(-speed.x, speed.y * deltatime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (!CheckCollisionWall(StObj, cS))
        {
            move(speed.x * deltatime, speed.y);
            c1->Move(speed.x * deltatime, speed.y);
            cO->Move(speed.x * deltatime, speed.y);
            cE->Move(speed.x * deltatime, speed.y);
            cN->Move(speed.x * deltatime, speed.y);
            cS->Move(speed.x * deltatime, speed.y);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {   
        if (!CheckCollisionWall(StObj, cE))
        {
            move(speed.x, speed.y * deltatime);
            c1->Move(speed.x, speed.y * deltatime);
            cO->Move(speed.x, speed.y * deltatime);
            cE->Move(speed.x, speed.y * deltatime);
            cN->Move(speed.x, speed.y * deltatime);
            cS->Move(speed.x, speed.y * deltatime);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        Weapon* weaponChange = holdWeapon;
        holdWeapon = secondaryWeapon;
        secondaryWeapon = weaponChange;
    }
}

//void Player::Shoot(std::vector <Bullet*> PlayerProjectiles)
//{
//    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//    {
//        Bullet* newBullet = new Bullet()
//            
//    }
//}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Entity::draw(target, states);

}