#include "pch.h"
#include "Alive.h"

Alive::Alive(int cHealth)
{
	maxHealth = cHealth;
	health = maxHealth;
}

void Alive::TakeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}
