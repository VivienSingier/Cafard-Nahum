#include "pch.h"
#include "SceneManager.h"
#include "StartMenu.h"
#include "SettingsScene.h"


SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
	scenes["StartMenu"] = new StartMenu();
	scenes["Level"] = new Level();
	scenes["SettingsScene"] = new SettingsScene();

	currentScene = scenes["StartMenu"];
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

void SceneManager::SetCurrentScene(std::string string)
{
	currentScene = scenes[string];
}

void SceneManager::Update(float deltatime)
{
	currentScene->Update(deltatime);
}