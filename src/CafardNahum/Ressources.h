#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>
#include <map>

class MapPath
{
	static MapPath* instance;

	std::vector < std::string > Floor1;
public:
	MapPath();
	static MapPath* GetInstance();
	void Init();
};

class StaticTextures
{
	static StaticTextures* instance;

public:
	sf::Texture doorOpened;
	sf::Texture doorClosed;

	std::map < std::string, sf::Texture > Floors;
	std::map < std::string, sf::Texture > Walls;
	std::map < std::string, sf::Texture > Bullets;
	std::map < std::string, sf::Texture > Weapons;

	std::map < std::string, sf::Texture > Enemies;
	std::map < std::string, sf::Texture > Boss;

	std::vector <sf::Texture> playerIdleCycleR;
	std::vector <sf::Texture> playerIdleCycleL;
	std::vector <sf::Texture> playerWalkCycleR;
	std::vector <sf::Texture> playerWalkCycleL;

	StaticTextures();
	static StaticTextures* GetInstance();
	void Init();
};
