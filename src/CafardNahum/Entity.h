#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Transformable, public sf::Drawable
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;

public:
	Entity(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale);
	virtual void Update(float deltatime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

