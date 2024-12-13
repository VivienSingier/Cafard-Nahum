#include "pch.h"
#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
	currentScene = new Level();
	scenes.push_back(currentScene);
}

SceneManager* SceneManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SceneManager();
	}
	return instance;
}

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}

void SceneManager::SetCurrentScene(Scene* scene)
{
	if (std::find(scenes.begin(), scenes.end(), scene) != scenes.end())
	{
		if (currentScene != scene)
		{
			currentScene = scene;
		}
	}
}

void SceneManager::Update(float deltatime)
{
	for (int i = 0; i < scenes.size(); i++)
	{
		scenes[i]->Update(deltatime);
	}
}