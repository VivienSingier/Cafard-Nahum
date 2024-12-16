#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Transformable, public sf::Drawable
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	bool needsToBeDestroyed;

public:
	Entity(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale);
	bool GetNeedsToBeDestroyed();
	virtual void Update(float deltatime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

