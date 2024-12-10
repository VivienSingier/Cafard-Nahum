#include "pch.h"
#include "Entity.h"

Entity::Entity(std::string path, sf::IntRect textureRect, sf::Vector2f position, sf::Vector2f scale)
{
    if (!texture.loadFromFile(path, textureRect))
    {
        return;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(scale);
}

void Entity::Update(float deltatime)
{

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(sprite, states);
}