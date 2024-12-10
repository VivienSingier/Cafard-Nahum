#pragma once
#include <vector>
#include "Scene.h"

class SceneManager
{
	std::vector <Scene*> scene;
	Scene* CurrentScene;

public :

	void GetCurrentScene();
	void SetCurrentScene();

};

