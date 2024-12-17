#include "pch.h"
#include "TwoFace.h"
#include "Ressources.h"

TwoFace::TwoFace(sf::Vector2f position) :
	Boss::Boss(&StaticTextures::GetInstance()->Boss["TwoFace"], position, sf::Vector2f(1.5, 1.5), sf::Vector2f(1, 1), 200)
{

}

void TwoFace::Shoot()
{

}