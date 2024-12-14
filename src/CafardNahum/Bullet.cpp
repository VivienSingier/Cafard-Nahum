#include "pch.h"
#include "Bullet.h"
#include "GameManager.h"

Bullet::Bullet(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f cSpeed) : 
	Entity::Entity(path, textureRect, position, scale),
	Movable::Movable(cSpeed),
	ColliderSphere::ColliderSphere()
{

}

void Bullet::Update(float deltatime)
{
	for(int i=0; i< bullets.size(); i++)
	{
		bullets[i]->Update(deltatime);
		bullets[i]->draw(GameManager::getInstance()->window, sf::RenderStates::Default); // Ne marche pas, A corriger
	}
}