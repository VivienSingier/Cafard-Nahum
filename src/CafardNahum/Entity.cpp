#include "pch.h"
#include "Entity.h"

Entity::Entity(float PosX, float PosY, float SheetX, float SheetY, float height, float width, std::string path, float ScaleX, float ScaleY)
{
    if (!texture.loadFromFile(path, sf::IntRect(SheetX, SheetY, width, height)))
    {
        return;
    }
    sprite.setTexture(texture);
    sprite.setPosition(PosX, PosY);
    sprite.setScale(sf::Vector2f(ScaleX, ScaleY));
}