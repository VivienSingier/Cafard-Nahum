#pragma once
#include "Bullet.h"

class ColliderSphere;

class TwoFaceCross1 :
    public Bullet
{
    ColliderSphere* c1;
    ColliderSphere* c2;
public:
    TwoFaceCross1(float x, float y, sf::Vector2f direction);
    void Move(float deltatiime) override;
    void HandleCollisions() override;
    void SpawnChildBullets();
    void Update(float deltatime) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

