#include "framework.h"
#include "enemy.hpp"
#include "player.hpp"

Enemy::Enemy(float x, float y, float heigth, float width, sf::Color color, Player* gamePlayer, float actorSpeed) : Character(x, y, heigth, width, color, actorSpeed)
{
    player = gamePlayer;
}

Enemy::~Enemy()
{
}

void Enemy::Update(float& dt) {
    sf::Vector2f direction = GetDirectionToPoint(player->GetX(), player->GetY());
    Move(direction.x * speed * dt, direction.y * speed * dt);
}