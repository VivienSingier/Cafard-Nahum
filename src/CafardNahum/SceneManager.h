#pragma once
#include <vector>
#include "Scene.h"
#include "Level.h"

class SceneManager
{
	std::vector <Scene*> scenes;
	Scene* currentScene;

public :
	SceneManager();
	Scene* GetCurrentScene();
	void SetCurrentScene(Scene* scene);

};

