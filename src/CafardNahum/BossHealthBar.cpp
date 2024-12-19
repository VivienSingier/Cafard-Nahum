#include "pch.h"
#include "BossHealthBar.h"
#include "GameManager.h"
#include "Ressources.h"
#include <iostream>

BossHealthBar::BossHealthBar(int cMaxHealth) :
	Entity(&StaticTextures::GetInstance()->UI["BossHealthBarEmpty"],
		sf::Vector2f(GameManager::getInstance()->window.getView().getCenter().x - 200, 
			GameManager::getInstance()->window.getView().getCenter().y - GameManager::getInstance()->window.getView().getSize().y / 2.0f + 20),
		sf::Vector2f(2, 2))
{
	maxHealth = cMaxHealth;
	health = maxHealth;

	path = "../../../res/imgStatic/healthbarContent.png";
	healthTexture.loadFromFile(path);
	healthSprite.setTexture(healthTexture);
	healthSprite.setOrigin(sf::Vector2f(0, 0));
	healthSprite.setScale(sprite.getScale());
}

void BossHealthBar::TakeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

void BossHealthBar::Update()
{
	float x = ((float)health / (float)maxHealth) * 200.f;
	healthSprite.setTextureRect(sf::IntRect(0, 0, x, 20));

	setPosition(GameManager::getInstance()->window.getView().getCenter().x - 200,
		GameManager::getInstance()->window.getView().getCenter().y - GameManager::getInstance()->window.getView().getSize().y / 2.0f + 20);
	healthSprite.setScale(sprite.getScale());
}

void BossHealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Entity::draw(target, states);
	states.transform.combine(getTransform());
	target.draw(healthSprite, states);
}