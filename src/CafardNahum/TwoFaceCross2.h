#pragma once
#include "Bullet.h"

class ColliderSphere;

class TwoFaceCross2 :
    public Bullet
{
    ColliderSphere* c1;
    sf::Vector2f target;

protected:
    sf::Clock liveClock;

public:
    TwoFaceCross2(float x, float y, sf::Vector2f direction);
    void Move(float deltatime) override;
    void HandleCollisions() override;
    void Update(float deltatime) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

