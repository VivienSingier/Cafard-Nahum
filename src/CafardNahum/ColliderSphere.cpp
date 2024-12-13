#include "pch.h"
#include "ColliderSphere.h"
#include "ColliderRect.h"

ColliderSphere::ColliderSphere(float radius, float x, float y) 
{
	sphere = sf::CircleShape(radius);
	sphere.setOrigin(sphere.getRadius(), sphere.getRadius());
	sphere.setPosition(x, y);
	sphere.setFillColor(sf::Color::Cyan);
}

bool ColliderSphere::GetCollisionWithRect(ColliderRect* colliderRect)
{
		float sphereX = sphere.getPosition().x;
		float sphereY = sphere.getPosition().y;

		float rectX = colliderRect->rect.getPosition().x + (colliderRect->rect.width / 2);
		float rectY = colliderRect->rect.getPosition().y + (colliderRect->rect.height / 2);

		float xDistance = abs(sphereX - rectX);
		float yDistance = abs(sphereY - rectY);

		if (xDistance < sphere.getRadius() + (colliderRect->rect.width / 2))
		{
			if (yDistance < sphere.getRadius() + (colliderRect->rect.height / 2))
			{
				return true;
			}
		}
		return false;
	
}

void ColliderSphere::Move(float x, float y)
{
	sphere.move(x, y);
}