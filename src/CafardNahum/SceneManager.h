#pragma once
#include <vector>
#include "Scene.h"
#include "Level.h"

class SceneManager
{
	static SceneManager* instance;
	std::vector <Scene*> scenes;
	Scene* currentScene;

public :
	SceneManager();
	static SceneManager* GetInstance();
	Scene* GetCurrentScene();
	void Update(float deltatime);
	void SetCurrentScene(Scene* scene);

};

