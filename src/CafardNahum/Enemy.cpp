#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth) :
	Entity::Entity(path, textureRect, position, scale),
	Movable::Movable(speed),
	Alive::Alive(cHealth),
	ColliderSphere::ColliderSphere()
{

}

//void Enemy::GetAngle(sf::Vector2f vector)
//{
//	GameManager::g
//	float enemyPositionX = sprite.getPosition().x + spriteWildht / 2;
//	float enemyPositionY = sprite.getPosition().y + spriteLenght / 2;
//	float playerPositionX = player.getPosition().x + PlayerWildth / 2;
//	float playerPositionY = player.getPosition().y + PlayerLenght / 2;
//
//	vector = sf::Vector2f(playerPositionX - enemyPositionX, playerPositionY - enemyPositionY);
//}