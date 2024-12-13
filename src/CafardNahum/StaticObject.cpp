#include "pch.h"
#include "StaticObject.h"

StaticObject::StaticObject(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale, bool cIsWalkable) :
	Entity(path, textureRect, position, scale)
{
	isWalkable = cIsWalkable;
	collisionRect = nullptr;
}

void StaticObject::SetIsWalkable(bool IsWalkable)
{
	isWalkable = IsWalkable;
}

bool StaticObject::GetIsWalkable()
{
	return isWalkable;
}