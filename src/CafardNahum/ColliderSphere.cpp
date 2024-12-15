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

bool ColliderSphere::GetCollisionWithSphere(ColliderSphere* colliderSphere)
{
	float xDistance = abs(sphere.getPosition().x - colliderSphere->sphere.getPosition().x);
	float yDistance = abs(sphere.getPosition().y - colliderSphere->sphere.getPosition().y);

	if (xDistance < sphere.getRadius() + colliderSphere->sphere.getRadius())
	{
		if (yDistance < sphere.getRadius() + colliderSphere->sphere.getRadius())
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