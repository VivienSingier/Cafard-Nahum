#pragma once
#include "SFML/Graphics.hpp"

class Movable
{
protected:
	sf::Vector2f speed;

public:
	Movable(sf::Vector2f cSpeed);
	virtual void Move(float deltatime);
};

