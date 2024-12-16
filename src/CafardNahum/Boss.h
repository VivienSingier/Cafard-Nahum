#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
public:
	Boss(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, sf::Vector2f speed, int cHealth);
	
};

