#include "pch.h"
#include "MayoBottle.h"
#include "GameManager.h"


MayoBottle::MayoBottle(float x, float y) :
	Weapon("../../../res/Weapon/mayo.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(x, y), sf::Vector2f(1, 1), sf::Vector2f(1, 1))
{
	this->setOrigin(0, 8);
}

void MayoBottle::Rotate(float angle)
{
	this->setRotation(angle);
}
