#include "pch.h"
#include "SceneManager.h"
#include "StartMenu.h"
#include "Victory.h"
#include "GameOver.h"
#include "SettingsScene.h"
#include "GameManager.h"


SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{
	scenes["StartMenu"] = new StartMenu();
	scenes["Level"] = new Level();
	scenes["Level"]->AddPlayer(GameManager::getInstance()->GetPlayer());
	scenes["SettingsScene"] = new SettingsScene();
	scenes["Victory"] = new Victory();
	scenes["GameOver"] = new GameOver();

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

void SceneManager::ResetLevel()
{
	GameManager::getInstance()->GetPlayer()->StartDelay();
	auto it = scenes.find("Levels");
	if (it != scenes.end())
	{
		scenes.erase(it);
	}
	delete scenes["Level"];

	scenes["Level"] = new Level();

	GameManager::getInstance()->GetPlayer()->SetPosition(sf::Vector2f(300.f, 400.f));
	GameManager::getInstance()->GetPlayer()->Heal();
	scenes["Level"]->AddPlayer(GameManager::getInstance()->GetPlayer());
}

void SceneManager::Update(float deltatime)
{
	if (!currentScene->GetStatus())
	{
		SetCurrentScene("Victory");
		ResetLevel();
	}
	else if (GameManager::getInstance()->GetPlayer()->GetHealth() == 0)
	{
		SetCurrentScene("GameOver");
		ResetLevel();
	}
	currentScene->Update(deltatime);
}