#include "pch.h"
#include "MayoBullet1.h"

MayoBullet1::MayoBullet1(float x, float y, sf::Vector2f direction) :
	Bullet("../../../res/Bullet/mayo1.png", sf::IntRect(0, 0, 18, 11), sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{

}