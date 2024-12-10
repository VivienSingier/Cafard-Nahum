#pragma once

class Alive
{
	int maxHealth;
	int health;

public:
	Alive(int cHealth);
	void TakeDamage(int damage);
};

