#include "pch.h"
#include "BossHealthBar.h"
#include "GameManager.h"
#include "Ressources.h"

BossHealthBar::BossHealthBar(int cMaxHealth) :
	Entity(&StaticTextures::GetInstance()->UI["BossHealthBarEmpty"],
		sf::Vector2f(GameManager::getInstance()->window.getView().getCenter().x - 400, 
			GameManager::getInstance()->window.getView().getCenter().y - GameManager::getInstance()->window.getView().getSize().y / 2.0f + 20),
		sf::Vector2f(2, 2))
{
	maxHealth = cMaxHealth;
	health = maxHealth;

	healthTexture = StaticTextures::GetInstance()->UI["BossHealthBarContent"];
	healthSprite.setTexture(healthTexture);
	healthSprite.setPosition(getPosition());
	healthSprite.setScale(getScale());
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
	float x = (health / maxHealth) * 200;
	healthSprite.setTextureRect(sf::IntRect(0, 0, x, 10));

	setPosition(GameManager::getInstance()->window.getView().getCenter().x - 400,
		GameManager::getInstance()->window.getView().getCenter().y - GameManager::getInstance()->window.getView().getSize().y / 2.0f + 20);
	healthSprite.setPosition(getPosition());
	healthSprite.setScale(getScale());
}

void BossHealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Entity::draw(target, states);
	target.draw(healthSprite);
}