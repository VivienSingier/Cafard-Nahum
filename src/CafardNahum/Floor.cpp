#include "pch.h"
#include "Floor.h"

Floor::Floor(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale) :
	StaticObject(path, textureRect, position, scale, true)
{
	sf::FloatRect* newRect = new sf::Rect <float>(position, sf::Vector2f(textureRect.width, textureRect.height));
	//rects.push_back(newRect);
	sprite.setOrigin(sf::Vector2f(0.f, sprite.getGlobalBounds().height));
}
