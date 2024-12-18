#include "pch.h"
#include "TwoFaceCross2.h"
#include "Ressources.h"

TwoFaceCross2::TwoFaceCross2(float x, float y, sf::Vector2f direction) :
	Bullet(&StaticTextures::GetInstance()->Bullets["TwoFaceCross2"],
		sf::Vector2f(x, y), sf::Vector2f(1, 1), direction)
{
	damage = 1;
	setOrigin(sf::Vector2f(8, 8));

	c1 = new ColliderSphere(7, x + 1, y + 1);
}

void TwoFaceCross2::Move(float deltatime)
{

}