#pragma once
#include <vector>
#include "Scene.h"
#include "Level.h"

class SceneManager
{
	std::vector <Scene*> scenes;
	Scene* currentScene;	
	static SceneManager* instance;

public :

	SceneManager();
	Scene* GetCurrentScene();
	static SceneManager* getInstance();
	void Update(float deltatime);
	void SetCurrentScene(Scene* scene);

};

