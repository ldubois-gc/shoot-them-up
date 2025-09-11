#include "framework.h"
#include "enemy_state.hpp"

#include "enemy.hpp"

void EnemyTracking::Update(Enemy& enemy, float dt) {
	enemy.Movement(dt);
}

void EnemyHit::Update(Enemy& enemy, float dt) {
    enemy.SetColor(sf::Color::Red);
    //enemy.Movement(dt);
    timer += dt;

    if (timer >= (dt * 4)) {
        timer = 0.0f;
        enemy.SetColor(sf::Color::Yellow);
        enemy.StateChange(&enemy.trackPlayer);
    }
}

void EnemyDying::Update(Enemy& enemy, float dt) {
    enemy.Kill();
}