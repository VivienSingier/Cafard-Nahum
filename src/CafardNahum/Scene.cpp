#include "pch.h"
#include "Scene.h"
Scene::Scene()
{
	Init();
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < entities.size(); i++)
	{
		target.draw(*(entities[i]));
	}
}