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

	StaticTextures();
	static StaticTextures* GetInstance();
	void Init();
};
