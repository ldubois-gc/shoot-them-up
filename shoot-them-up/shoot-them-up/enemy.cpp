#include "framework.h"
#include "enemy.hpp"
#include "player.hpp"

#include <cmath>

Enemy::Enemy(float x, float y, sf::Color color, Player* gamePlayer, float actorSpeed) : Character(x, y, color, actorSpeed)
{
    player = gamePlayer;
}

Enemy::~Enemy()
{
}

void Enemy::Update(float& dt) {
    float distanceWithPlayerX = player->GetX() - xPos;
    float distanceWithPlayerY = player->GetY() - yPos;

    // 1. Norme
    float norme = sqrt(pow(distanceWithPlayerX, 2) + pow(distanceWithPlayerY, 2));

    // 2. Normalisation
    float normeX = distanceWithPlayerX / norme;
    float normeY = distanceWithPlayerY / norme;

    Move(normeX * speed * dt, normeY * speed * dt);
}