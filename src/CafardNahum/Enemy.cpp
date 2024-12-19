#include "pch.h"
#include "Enemy.h"
#include "GameManager.h"
#include "Player.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth) :
	Entity::Entity(texture, position, scale),
	Movable::Movable(speed),
	Alive::Alive(cHealth)
{
    hitClock.restart();
    isColored = false;
}

float Enemy::GetShotAngle()
{
	sf::Vector2f playerPos = GameManager::getInstance()->GetPlayer()->getPosition();
	sf::Vector2f pos = getPosition();

	float angle = atan2((playerPos.y - pos.y), playerPos.x - pos.x);
	angle *= (180.0 / 3.141592653589793238463);

	return angle;
}

void Enemy::Hit()
{

    if (isColored)
    {
        if (hitClock.getElapsedTime().asSeconds() > 0.2f)
        {
            isColored = false;
            sprite.setColor(sf::Color(255, 255, 255));
        }
        else
        {
            sprite.setColor(sf::Color(255, 0, 0));
        }
    }
}