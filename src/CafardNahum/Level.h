#pragma once
#include "Scene.h"
#include "Player.h"

class Room;
class Corridoor;
class TwoFace;

class Level : public Scene
{
	TwoFace* tFace;
	bool isTfaceAlive;

public:
	Level();
	void Update(float deltatime) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool GetStatus() override;
};

