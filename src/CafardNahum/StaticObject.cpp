#include "pch.h"
#include "StaticObject.h"

StaticObject::StaticObject(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale) :
	Entity(path, textureRect, position, scale)
{

}
