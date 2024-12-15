#include "pch.h"
#include "MayoBottle.h"
#include "GameManager.h"


MayoBottle::MayoBottle(float x, float y) :
	Weapon("../../../res/Weapon/mayo.png", sf::IntRect(0, 0, 16, 16), sf::Vector2f(x, y), sf::Vector2f(2, 2), sf::Vector2f(1, 1))
{

}

void MayoBottle::Rotate(float angle)
{
	
}
