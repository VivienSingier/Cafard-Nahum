#include "pch.h"
#include "Enemy.h"
#include "GameManager.h"

Enemy::Enemy(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, int cHealth, sf::Vector2f speed) :
	Entity::Entity(path, textureRect, position, scale),
	Movable::Movable(speed),
	Alive::Alive(cHealth),
	ColliderSphere::ColliderSphere()
{

}

void Enemy::Update(float deltatime)
{
}

void Enemy::GetAngle(sf::Vector2f target)
{
	
	float enemyPositionX = sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
	float enemyPositionY = sprite.getPosition().y + sprite.getGlobalBounds().height / 2;
	float playerPositionX = GameManager::getInstance()->GetPlayer()->getPosition().x;
	float playerPositionY = GameManager::getInstance()->GetPlayer()->getPosition().y;

	target = sf::Vector2f(playerPositionX - enemyPositionX, playerPositionY - enemyPositionY);
}