#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Entity : sf::Transformable, sf::Drawable
{
	sf::Sprite sprite;
	sf::Texture texture;

public:
	Entity(float PosX, float PosY, float SheetX, float SheetY, float height, float width, std::string path, float ScaleX, float ScaleY);
	virtual void Update(float deltatime);
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states);

};

