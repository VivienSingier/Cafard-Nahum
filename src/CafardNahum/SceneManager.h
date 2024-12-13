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
	void Update(float deltatime);
	void SetCurrentScene(Scene* scene);

};

