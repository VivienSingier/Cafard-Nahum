#include "pch.h"
#include "Door.h"

Door::Door(sf::Vector2f position) :
	StaticObject("../../../res/imgStatic/floor1.png", sf::IntRect(32, 0, 16, 16), position, sf::Vector2f(2, 2), true)
{
	isOpen = true;
	sprite.setOrigin(sf::Vector2f(0.f, sprite.getGlobalBounds().height));

	closedTexture.loadFromFile("../../../res/imgStatic/floor1.png", sf::IntRect(48, 0, 16, 32));
	closedSprite.setTexture(closedTexture);
	closedSprite.setOrigin(sf::Vector2f(0.f, closedSprite.getGlobalBounds().height));
	closedSprite.setScale(sf::Vector2f(2.f, 2.f));
	closedSprite.setPosition(sprite.getPosition());
	closedSprite.move(0, -32.f);

	collisionRect = new ColliderRect(position.x, position.y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

void Door::Open()
{
	if (!isOpen)
	{
		sf::Sprite tempSprite = sprite;
		sprite = closedSprite;
		closedSprite = tempSprite;
		isOpen = true;
		SetIsWalkable(true);
	}
}

void Door::Close()
{
	if (isOpen)
	{
		sf::Sprite tempSprite = sprite;
		sprite = closedSprite;
		closedSprite = tempSprite;
		isOpen = false;
		SetIsWalkable(false);
	}
}