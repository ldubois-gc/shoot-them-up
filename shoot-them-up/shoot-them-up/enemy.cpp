#include "framework.h"
#include "enemy.hpp"
#include "player.hpp"
#include "obstacle.hpp"
#include "manager.hpp"

Enemy::Enemy() : stateMachine(*this) {

}

Enemy::~Enemy()
{
}

void Enemy::Init(float x, float y, float height, float width, sf::Color color, Manager* manager, Player* gamePlayer, float actorSpeed) {
    Character::Init(x, y, height, width, color, manager, actorSpeed);
    player = gamePlayer;
    collideObstacle = false;
    stateMachine.ChangeState(&trackPlayer);
    healthPoints = 10;
}

void Enemy::OnCollision(Entity* collidedEntity) {
    if (collidedEntity->Type() == EntityType::OBSTACLE || collidedEntity->Type() == EntityType::ENEMY) {
        PushBack(collidedEntity);
    }
    if (collidedEntity->Type() == EntityType::OBSTACLE) {
        collideObstacle = true;
    }
    if (collidedEntity->Type() == EntityType::PROJECTILE) {
        StateChange(&enemyHit);
        healthPoints -= 1;
    }
}

void Enemy::Update(float& dt) {
    if (healthPoints <= 0) {
        StateChange(&killed);
    }
    stateMachine.Update(dt);
}

void Enemy::Movement(float& dt) {

    float currentSpeed = speed;

    float xMove = 0.f;
    float yMove = 0.f;

    timer += dt;

    if (timer >= dt * 120)
        collideObstacle = false;

    if (collideObstacle) {
        playerDirection = GetDirectionToPoint(xPos < player->GetX() ? xPos - 100000.f : xPos + 100000.f, yPos < player->GetY() ? yPos - 100000.f : yPos + 100000.f);
    }
    else {
        playerDirection = GetDirectionToPoint(player->GetX(), player->GetY());
    }

    xMove = playerDirection.x * currentSpeed * dt;
    yMove = playerDirection.y * currentSpeed * dt;

    Move(xMove, yMove);
}

void Enemy::StateChange(State<Enemy>* newState) {
    stateMachine.ChangeState(newState);
}