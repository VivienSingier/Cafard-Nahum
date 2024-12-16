#include "pch.h"
#include "Entity.h"

Entity::Entity(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale)
{
    this->setPosition(position);
    sprite.setTexture(*texture);
    sprite.setScale(scale);
    needsToBeDestroyed = false;
}

bool Entity::GetNeedsToBeDestroyed()
{
    return needsToBeDestroyed;
}

void Entity::Update(float deltatime)
{

}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(sprite, states);
}

