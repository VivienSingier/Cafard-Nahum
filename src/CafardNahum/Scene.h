#pragma once
#include "Entity.h"
#include <vector>

class Player;
class Enemy;
class Bullet;

class Scene : public sf::Drawable
{
protected:
	std::vector <Entity*> entities;


public:
	std::vector <Bullet*> PlayerProjectiles;
	std::vector <Bullet*> EnemyProjectiles;

	Scene();
	void Init();
	void AddPlayer(Player* player);
	void AddEnemy(Enemy* enemy);
	void Update(float deltatime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

