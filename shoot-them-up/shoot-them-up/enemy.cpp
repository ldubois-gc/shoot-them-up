#include "framework.h"
#include "enemy.hpp"

Enemy::Enemy(float x, float y, sf::Color color, float actorSpeed) : Actor(x, y, color, actorSpeed)
{
}

Enemy::~Enemy()
{
}


void Enemy::Update(float& dt) {
    if (xPos != 750.f) {
        Move(speed * dt, 0.0f);
    }

    /*if (playerInput->IsKeyDown(VK_UP))
    {
        Move(0.0f, -speed * dt);
    }
    if (playerInput->IsKeyDown(VK_DOWN))
    {
        Move(0.0f, speed * dt);
    }
    if (playerInput->IsKeyDown(VK_RIGHT))
    {
        Move(speed * dt, 0.0f);
    }
    if (playerInput->IsKeyDown(VK_LEFT))
    {
        Move(-speed * dt, 0.0f);
    }*/
}