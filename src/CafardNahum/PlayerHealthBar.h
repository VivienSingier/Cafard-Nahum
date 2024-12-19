#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class PlayerHealthBar : public sf::Drawable, sf::Transformable
{
	int maxHealth;
	int health;
	sf::Texture txtEnd;
	sf::Texture txtMid;
	sf::Texture txtStrt;

	std::vector <sf::Sprite*> firstLine;
	std::vector <sf::Sprite*> secondLine;

public:
	PlayerHealthBar();
	void TakeDamage(int damage);
	void Update(float deltatime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

