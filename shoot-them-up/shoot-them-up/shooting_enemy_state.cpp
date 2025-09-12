#include "framework.h"
#include "shooting_enemy_state.hpp"

#include "shooting_enemy.hpp"

void ShootingEnemyTracking::Update(ShootingEnemy& shootingEnemy, float dt) {
	shootingEnemy.Movement(dt);
}

void ShootingEnemyHit::Update(ShootingEnemy& shootingEnemy, float dt) {
    shootingEnemy.SetColor(sf::Color::Red);
    timer += dt;

    if (timer >= dt * 4) {
        timer = 0.0f;
        shootingEnemy.SetColor(sf::Color::Cyan);
        shootingEnemy.StateChange(&shootingEnemy.trackPlayer);
    }
}

void ShootingEnemyDying::Update(ShootingEnemy& shootingEnemy, float dt) {
    shootingEnemy.Kill();
}