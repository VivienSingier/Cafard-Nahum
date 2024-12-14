#pragma once
#include "StaticObject.h"

class Door : public StaticObject
{
	bool isOpen;
	sf::Sprite closedSprite;
	sf::Texture closedTexture;

public:
	Door(sf::Vector2f position);
	bool GetIsOpen();
	void Open();
	void Close();
};

