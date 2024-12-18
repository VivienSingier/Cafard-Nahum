#include "pch.h"
#include "TwoFaceSeekingChild.h"

TwoFaceSeekingChild::TwoFaceSeekingChild(float x, float y) :
	TwoFaceCross2(x, y, sf::Vector2f(0, 0))
{

}

void TwoFaceSeekingChild::Update(float deltatime)
{
	HandleCollisions();
	if (liveClock.getElapsedTime().asSeconds() > 5.0f)
	{
		needsToBeDestroyed = true;
	}
}