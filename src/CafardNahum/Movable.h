#pragma once
#include "SFML/Graphics.hpp"

class Movable
{
	sf::Vector2f speed;

public:
	virtual void Move(float deltatime);
};

