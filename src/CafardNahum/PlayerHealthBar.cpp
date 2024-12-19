#include "pch.h"
#include "PlayerHealthBar.h"
#include "GameManager.h"
#include "Ressources.h"
#include "SceneManager.h"

PlayerHealthBar::PlayerHealthBar()
{
	maxHealth = 10;
	health = 10;

	txtStrt = StaticTextures::GetInstance()->UI["PlayerHealthBarStart"];
	txtMid = StaticTextures::GetInstance()->UI["PlayerHealthBarMid"];
	txtEnd = StaticTextures::GetInstance()->UI["PlayerHealthBarEnd"];

	sf::Vector2f viewPos = sf::Vector2f(GameManager::getInstance()->window.getView().getCenter().x - GameManager::getInstance()->window.getView().getSize().x / 2.0f + 20,
		GameManager::getInstance()->window.getView().getCenter().y - GameManager::getInstance()->window.getView().getSize().y / 2.0f + 20);

	sf::Sprite* s1 = new sf::Sprite();
	s1->setTexture(txtEnd);
	s1->setPosition(viewPos);
	firstLine.push_back(s1);

	for (int i = 1; i < 4; i++)
	{
		sf::Sprite* s = new sf::Sprite();
		s->setTexture(txtMid);
		s->setPosition(viewPos.x + 18 * i, viewPos.y);
		firstLine.push_back(s);
	}

	sf::Sprite* s5 = new sf::Sprite();
	s5->setTexture(txtStrt);
	s5->setPosition(viewPos.x + 18 * 4, viewPos.y);
	firstLine.push_back(s5);

	sf::Sprite* s6 = new sf::Sprite();
	s6->setTexture(txtEnd);
	s6->setPosition(viewPos.x , viewPos.y + 22);
	secondLine.push_back(s6);

	for (int i = 1; i < 4; i++)
	{
		sf::Sprite* s = new sf::Sprite();
		s->setTexture(txtMid);
		s->setPosition(viewPos.x + 18 * i, viewPos.y + 22);
		secondLine.push_back(s);
	}

	sf::Sprite* s10 = new sf::Sprite();
	s10->setTexture(txtStrt);
	s10->setPosition(viewPos.x + 18 * 4, viewPos.y + 22);
	secondLine.push_back(s10);
}

void PlayerHealthBar::TakeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}

void PlayerHealthBar::Update(float deltatime)
{
	sf::Vector2f viewPos = sf::Vector2f(SceneManager::GetInstance()->GetCurrentScene()->view->getCenter().x - SceneManager::GetInstance()->GetCurrentScene()->view->getSize().x / 2.0f + 20,
		SceneManager::GetInstance()->GetCurrentScene()->view->getCenter().y - SceneManager::GetInstance()->GetCurrentScene()->view->getSize().y / 2.0f + 20);

	for (int i = 0; i < firstLine.size(); i++)
	{
		firstLine[i]->setPosition(sf::Vector2f(viewPos.x + 18 * i, viewPos.y));
	}
	for (int i = 0; i < secondLine.size(); i++)
	{
		secondLine[i]->setPosition(sf::Vector2f(viewPos.x + 18 * i, viewPos.y + 22));
	}

}

void PlayerHealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (health > 5)
	{
		for (int i = 0; i < (health - 5); i++)
		{
			target.draw(*secondLine[i]);
		}
		for (int i = 0; i <  5; i++)
		{
			target.draw(*firstLine[i]);
		}
	}
	else
	{
		for (int i = 0; i < health ; i++)
		{
			target.draw(*firstLine[i]);
		}
	}
}




