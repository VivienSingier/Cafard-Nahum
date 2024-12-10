#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entity : sf::Transformable, sf::Drawable
{
	sf::Sprite sprite;
	sf::Texture texture;

public:
	Entity(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale);
	virtual void Update(float deltatime);
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states);

};

