#pragma once
#include "Entity.h"
#include <string>

class BossHealthBar : public Entity
{
	int health;
	int maxHealth;

	std::string path;

	sf::Sprite healthSprite;
	sf::Texture healthTexture;

public:
	BossHealthBar(int maxHealth);
	void TakeDamage(int damage);
	void Update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

