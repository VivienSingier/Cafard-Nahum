#include "pch.h"
#include "Enemy.h"
#include "GameManager.h"

Enemy::Enemy(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth) :
	Entity::Entity(path, textureRect, position, scale),
	Movable::Movable(speed),
	Alive::Alive(cHealth),
	ColliderSphere::ColliderSphere()
{

}

//void Enemy::GetAngle(sf::Vector2f vector)
//{
//	float enemyPositionX = sprite.getPosition().x + sprite.getGlobalBounds().width / 2;
//	float enemyPositionY = sprite.getPosition().y + sprite.getGlobalBounds().height / 2;
//	float playerPositionX = player.getPosition().x + PlayerWildth / 2;
//	float playerPositionY = player.getPosition().y + PlayerLenght / 2;
//
//	vector = sf::Vector2f(playerPositionX - enemyPositionX, playerPositionY - enemyPositionY);
//}