#include "pch.h"
#include "ColliderRect.h"

ColliderRect::ColliderRect(float x, float y, float width, float height)
{
	rect = sf::FloatRect(x, y, width, height);
}