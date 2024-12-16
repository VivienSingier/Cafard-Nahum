#include "pch.h"
#include "StaticObject.h"

StaticObject::StaticObject(sf::Texture, sf::Vector2f position, sf::Vector2f scale, bool cIsWalkable) :
	Entity(texture, position, scale)
{
	isWalkable = cIsWalkable;
}

void StaticObject::SetIsWalkable(bool IsWalkable)
{
	isWalkable = IsWalkable;
}

bool StaticObject::GetIsWalkable()
{
	return isWalkable;
}