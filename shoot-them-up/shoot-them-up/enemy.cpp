#include "framework.h"
#include "enemy.hpp"
#include "player.hpp"
#include "obstacle.hpp"
#include "manager.hpp"
#include "projectile.hpp"

Enemy::Enemy() : stateMachine(*this) {

}

Enemy::~Enemy()
{
}

void Enemy::Init(float x, float y, float height, float width, sf::Color color, Manager* manager, Player* gamePlayer, std::vector<Obstacle*>* allObstacles, float actorSpeed) {
    Character::Init(x, y, height, width, color, manager, actorSpeed);
    player = gamePlayer;
    collideObstacle = false;
    moveX = false;
    stateMachine.ChangeState(&trackPlayer);
    healthPoints = 10;
    obstacles = allObstacles;
}

void Enemy::OnCollision(Entity* collidedEntity) {
    if (collidedEntity->Type() == EntityType::OBSTACLE || collidedEntity->Type() == EntityType::ENEMY) {
        PushBack(collidedEntity);
    }
    if (collidedEntity->Type() == EntityType::OBSTACLE) {
        collideObstacle = true;
    }
    if (collidedEntity->Type() == EntityType::PROJECTILE && static_cast<Projectile*>(collidedEntity)->GetShooter()->Type() != EntityType::ENEMY) {
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

    if (collideObstacle) {
        timer += dt;

        if (timer >= dt * 100)
            moveX = !moveX;

        if (timer >= dt * 200) {
            collideObstacle = false;
            timer = 0;
        }

        if (moveX) {
            playerDirection = GetDirectionToPoint(xPos > player->GetX() + 100 ? xPos - 100.f : xPos + 100.f, player->GetY());
        }
        else {
            playerDirection = GetDirectionToPoint(player->GetX(), yPos > player->GetY() + 100 ? yPos - 100.f : yPos + 100.f);
        }
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