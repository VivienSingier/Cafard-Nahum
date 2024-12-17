#pragma once

class Alive
{
protected:
	int maxHealth;
	int health;

public:
	Alive(int cHealth);
	virtual void TakeDamage(int damage);
};

