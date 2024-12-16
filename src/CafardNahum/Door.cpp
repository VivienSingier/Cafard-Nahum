#include "pch.h"
#include "Door.h"
#include "Ressources.h"

Door::Door(sf::Vector2f position) :
	StaticObject(StaticTextures::GetInstance()->doorOpened, position, sf::Vector2f(2, 2), true)
{
	isOpen = true;
	sprite.setOrigin(sf::Vector2f(0.f, sprite.getGlobalBounds().height));

	closedTexture = StaticTextures::GetInstance()->doorClosed;
	closedSprite.setTexture(closedTexture);
	closedSprite.setOrigin(sf::Vector2f(0.f, closedSprite.getGlobalBounds().height));
	closedSprite.setScale(sf::Vector2f(2.f, 2.f));
	closedSprite.setPosition(sprite.getPosition());
	closedSprite.move(0, -32.f);

	collisionRect = new ColliderRect(position.x, position.y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

bool Door::GetIsOpen()
{
	return isOpen;
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