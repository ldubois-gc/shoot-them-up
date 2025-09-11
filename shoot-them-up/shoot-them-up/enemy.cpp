#include "framework.h"
#include "enemy.hpp"
#include "player.hpp"

Enemy::Enemy(float x, float y, float heigth, float width, sf::Color color, Manager* manager, Player* gamePlayer, float actorSpeed) : Character(x, y, heigth, width, color, manager, actorSpeed)
{
    player = gamePlayer;
}

Enemy::~Enemy()
{
}

void Enemy::OnCollision(Entity* collidedEntity) {
    if (collidedEntity->Type() == EntityType::OBSTACLE || collidedEntity->Type() == EntityType::ENEMY) {
        PushBack(collidedEntity);
    }
}

void Enemy::Update(float& dt) {
    sf::Vector2f direction = GetDirectionToPoint(player->GetX(), player->GetY());

    float currentSpeed = speed;

    float xMove = direction.x * currentSpeed * dt + correctionX;
    float yMove = direction.y * currentSpeed * dt + correctionY;

    Move(xMove, yMove);

    correctionX = 0;
    correctionY = 0;
}