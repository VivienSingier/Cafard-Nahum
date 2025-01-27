#include "pch.h"
#include "Ressources.h"

MapPath* MapPath::instance = nullptr;
StaticTextures* StaticTextures::instance = nullptr;

MapPath::MapPath()
{
	Init();
}

StaticTextures::StaticTextures()
{
	Init();
}

MapPath* MapPath::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MapPath();
	}
	return instance;
}

StaticTextures* StaticTextures::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new StaticTextures();
	}
	return instance;
}

void MapPath::Init()
{
	Floor1.push_back("../../../res/Maps/Floor1/1.txt");
	Floor1.push_back("../../../res/Maps/Floor1/2.txt");
	Floor1.push_back("../../../res/Maps/Floor1/3.txt");
}

void StaticTextures::Init()
{
	doorOpened.loadFromFile("../../../res/imgStatic/floor1.png", sf::IntRect(32, 0, 16, 16));
	doorClosed.loadFromFile("../../../res/imgStatic/floor1.png", sf::IntRect(48, 0, 16, 32));

	Floors["Blue1"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(0, 0, 16, 16));
	Floors["Blue2"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(0, 16, 16, 16));
	Floors["Blue3"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(0, 32, 16, 16));
	Floors["Blue4"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(0, 48, 16, 16));
	Floors["Blue5"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(0, 64, 16, 16));
	Floors["Blue6"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(0, 80, 16, 16));

	//Floors["Ice1"] = sf::IntRect(16, 0, 16, 16);
	//Floors["Ice2"] = sf::IntRect(16, 16, 16, 16);
	//Floors["Ice3"] = sf::IntRect(16, 32, 16, 16);
	//Floors["Ice4"] = sf::IntRect(16, 48, 16, 16);
	//Floors["Ice5"] = sf::IntRect(16, 64, 16, 16);
	//Floors["Ice6"] = sf::IntRect(16, 80, 16, 16);

	Floors["Purple1"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(0, 32, 16, 16));
	Floors["Purple2"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(16, 32, 16, 16));
	Floors["Purple3"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(32, 32, 16, 16));
	Floors["Purple4"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(48, 32, 16, 16));
	Floors["Purple5"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(64, 32, 16, 16));
	Floors["Purple6"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(80, 32, 16, 16));

	Floors["White1"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(0, 190, 16, 16));
	Floors["Black1"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(16, 190, 16, 16));
	Floors["White2"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(32, 190, 16, 16));
	Floors["Black2"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(48, 190, 16, 16));

	Floors["WoodHor"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(0, 206, 16, 16));
	Floors["WoodVert"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(16, 206, 16, 16));

	//Floors["Black1"] = sf::IntRect(48, 0, 16, 16);
	//Floors["Black2"] = sf::IntRect(48, 16, 16, 16);
	//Floors["Black3"] = sf::IntRect(48, 32, 16, 16);
	//Floors["Black4"] = sf::IntRect(48, 48, 16, 16);
	//Floors["Black5"] = sf::IntRect(48, 64, 16, 16);
	//Floors["Black6"] = sf::IntRect(48, 80, 16, 16);

	Walls["PurpleTop1"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(96, 32, 16, 16));
	Walls["PurpleBottom1"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(96, 48, 16, 16));
	Walls["PurpleTop2"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(96, 32, 16, 16));
	Walls["PurpleBottom2"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(96, 80, 16, 16));

	Walls["WallTop"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(64, 190, 16, 16));
	Walls["WallBottom"].loadFromFile("../../../res/imgStatic/floorTiles.png", sf::IntRect(64, 206, 16, 16));

	Bullets["MayoBullet"].loadFromFile("../../../res/Bullet/mayo1.png", sf::IntRect(0, 0, 18, 11));
	Bullets["PoisonBullet1"].loadFromFile("../../../res/Bullet/PoisonBullet1.png", sf::IntRect(1, 1, 17, 11));
	Bullets["PoisonBullet2"].loadFromFile("../../../res/Bullet/PoisonBullet2.png", sf::IntRect(1, 1, 18, 18));
	Bullets["TwoFaceSpiral"].loadFromFile("../../../res/Bullet/twoFaceSpiral.png", sf::IntRect(1, 1, 18, 18));
	Bullets["TwoFaceCross1"].loadFromFile("../../../res/Bullet/twoFaceCross1.png", sf::IntRect(0, 0, 18, 11));
	Bullets["TwoFaceCross2"].loadFromFile("../../../res/Bullet/twoFaceCross2.png", sf::IntRect(0, 0, 16, 16));
	Bullets["TwoFaceSeeking"].loadFromFile("../../../res/Bullet/twoFaceSeeking.png", sf::IntRect(1, 1, 17, 11));
	Bullets["Pepper"].loadFromFile("../../../res/Bullet/pepper.png", sf::IntRect(0, 0, 16, 16));
	Bullets["Salt"].loadFromFile("../../../res/Bullet/salt.png", sf::IntRect(0, 0, 16, 16));

	Weapons["MayoBottle"].loadFromFile("../../../res/Weapon/mayo.png", sf::IntRect(0, 0, 16, 16));
	Weapons["PepperGun"].loadFromFile("../../../res/Weapon/pepperGun.png", sf::IntRect(0, 0, 16, 16));

	Boss["TwoFace"].loadFromFile("../../../res/Enemies/twoFace.png", sf::IntRect(0, 0, 64, 64));

	UI["BossHealthBarEmpty"].loadFromFile("../../../res/imgStatic/healthbarEmpty.png", sf::IntRect(0, 0, 200, 10));
	UI["BossHealthBar"].loadFromFile("../../../res/imgStatic/healthbarContent.png");
	UI["PlayerHealthBarStart"].loadFromFile("../../../res/imgStatic/healthBarStart.png");
	UI["PlayerHealthBarMid"].loadFromFile("../../../res/imgStatic/healthBarMid.png");
	UI["PlayerHealthBarEnd"].loadFromFile("../../../res/imgStatic/healthBarEnd.png");

	MenuTexture.loadFromFile("../../../res/imgStatic/StartMenu.jpg");
	PlayButton.loadFromFile("../../../res/imgStatic/PlayButton.png", sf::IntRect(0, 24, 100, 43));
	PlayButton2.loadFromFile("../../../res/imgStatic/PlayButton2.png", sf::IntRect(0, 24, 100, 43));
	SettingsButton.loadFromFile("../../../res/imgStatic/SettingsButton.png", sf::IntRect(0, 24, 100, 43));
	SettingsButton2.loadFromFile("../../../res/imgStatic/SettingsButton2.png", sf::IntRect(0, 24, 100, 43));
	QuitButton.loadFromFile("../../../res/imgStatic/QuitButton.png", sf::IntRect(0, 24, 100, 43));
	QuitButton2.loadFromFile("../../../res/imgStatic/QuitButton2.png", sf::IntRect(0, 24, 100, 43));
	BackButton.loadFromFile("../../../res/imgStatic/BackButton.png", sf::IntRect(0, 24, 100, 43));
	BackButton2.loadFromFile("../../../res/imgStatic/BackButton2.png", sf::IntRect(0, 24, 100, 43));
	RestartButton.loadFromFile("../../../res/imgStatic/RestartButton.png", sf::IntRect(0, 24, 100, 43));
	RestartButton2.loadFromFile("../../../res/imgStatic/RestartButton2.png", sf::IntRect(0, 24, 100, 43));
	MainMenuButton.loadFromFile("../../../res/imgStatic/MainMenuButton.png", sf::IntRect(0, 24, 100, 43));
	MainMenuButton2.loadFromFile("../../../res/imgStatic/MainMenuButton2.png", sf::IntRect(0, 24, 100, 43));
	Victory.loadFromFile("../../../res/imgStatic/Victory.png", sf::IntRect(0, 24, 100, 100));
	GameOver.loadFromFile("../../../res/imgStatic/GameOver.png", sf::IntRect(0, 24, 100, 100));

	text.loadFromFile("../../../res/Text/Text1.ttf");

	sf::Texture walkCycleR1;
	walkCycleR1.loadFromFile("../../../res/Player/PlayerSpriteSheet.png", sf::IntRect(8, 7, 11, 21));
	playerIdleCycleR.push_back(walkCycleR1);

	sf::Texture pWalkCycleR1;
	pWalkCycleR1.loadFromFile("../../../res/Enemies/PoisonRoach.png", sf::IntRect(5, 43, 35, 35));
	poisonRoachWalkCycleR.push_back(pWalkCycleR1);
}