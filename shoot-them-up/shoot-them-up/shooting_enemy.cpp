#include "framework.h"
#include "shooting_enemy.hpp"
#include "player.hpp"
#include "obstacle.hpp"
#include "manager.hpp"
#include "projectile.hpp"

class Obstacle;

ShootingEnemy::ShootingEnemy() : stateMachine(*this)
{
}

ShootingEnemy::~ShootingEnemy()
{
}

void ShootingEnemy::Init(float x, float y, float height, float width, sf::Color color, Manager* manager, Player* gamePlayer, std::vector<Obstacle*>* allObstacles, float actorSpeed) {
    Enemy::Init(x, y, height, width, color, manager, gamePlayer, allObstacles, actorSpeed);
    stateMachine.ChangeState(&trackPlayer);
    shootCooldown = 1.5f;
}

void ShootingEnemy::OnCollision(Entity* collidedEntity) {
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

void ShootingEnemy::Movement(float& dt) {
    if (!IsAimHittingPlayer()) {
        Enemy::Movement(dt);
    }

    shootTimer += dt;
    if ((shootTimer >= shootCooldown)) {
        Shoot();
        shootTimer = 0.f;
    }
}

void ShootingEnemy::Shoot() {
    gameManager->CreateProjectile(xPos, yPos, playerDirection.x, playerDirection.y, 600.0f, static_cast<Character*>(this));
}

void ShootingEnemy::Update(float& dt) {
    if (healthPoints <= 0) {
        StateChange(&killed);
    }
    stateMachine.Update(dt);
}

bool ShootingEnemy::IsAimHittingPlayer() {
    /*float x2 = player->GetX();
    float y2 = player->GetY();

    for (Obstacle* obstacle : *obstacles) {
        float obstacleX = obstacle->GetX();
        float obstacleY = obstacle->GetY();
        float obstacleH = obstacle->GetHeigth();
        float obstacleW = obstacle->GetWidth();

        bool hitLeft = LineLine(xPos, yPos, x2, y2, obstacleX, obstacleY, obstacleX, obstacleY + obstacleX);
        bool hitRight = LineLine(xPos, yPos, x2, y2, obstacleX + obstacleW, obstacleY, obstacleX + obstacleW, obstacleH);
        bool hitTop = LineLine(xPos, yPos, x2, y2, obstacleX, obstacleY, obstacleX + obstacleH, obstacleY);
        bool hitBottom = LineLine(xPos, yPos, x2, y2, obstacleX, obstacleY + obstacleH, obstacleX + obstacleW, obstacleY + obstacleH);

        if(hitLeft || hitRight || hitTop || hitBottom)
            return false;
    }

    return true;*/

    return false;
}

bool ShootingEnemy::LineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    return uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1;
}

void ShootingEnemy::StateChange(State<ShootingEnemy>* newState) {
    stateMachine.ChangeState(newState);
}