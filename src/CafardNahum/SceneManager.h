#pragma once
#include <vector>
#include <map>
#include <string>
#include "Scene.h"
#include "Level.h"

class SceneManager
{
	static SceneManager* instance;
	std::map <std::string, Scene*> scenes;
	Scene* currentScene;

public :
	SceneManager();
	static SceneManager* GetInstance();
	Scene* GetCurrentScene();
	void Update(float deltatime);
	void SetCurrentScene(std::string);

};

