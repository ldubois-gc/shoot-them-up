#include "framework.h"
#include "enemy.hpp"
#include "player.hpp"
#include "manager.hpp"

Enemy::Enemy() : stateMachine(*this) {

}

Enemy::~Enemy()
{
}

void Enemy::Init(float x, float y, float height, float width, sf::Color color, Manager* manager, Player* gamePlayer, float actorSpeed) {
    Character::Init(x, y, height, width, color, manager, actorSpeed);
    player = gamePlayer;
    stateMachine.ChangeState(&trackPlayer);
    healthPoints = 10;
}

void Enemy::OnCollision(Entity* collidedEntity) {
    if (collidedEntity->Type() == EntityType::OBSTACLE || collidedEntity->Type() == EntityType::ENEMY) {
        PushBack(collidedEntity);
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
    playerDirection = GetDirectionToPoint(player->GetX(), player->GetY());

    float currentSpeed = speed;

    float xMove = playerDirection.x * currentSpeed * dt;
    float yMove = playerDirection.y * currentSpeed * dt;

    Move(xMove, yMove);
}

void Enemy::StateChange(State<Enemy>* newState) {
    stateMachine.ChangeState(newState);
}