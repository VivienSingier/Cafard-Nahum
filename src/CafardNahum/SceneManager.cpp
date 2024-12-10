#include "pch.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
	currentScene = new Scene();
	scenes.push_back(currentScene);
}