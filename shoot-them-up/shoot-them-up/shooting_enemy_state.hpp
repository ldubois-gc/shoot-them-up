#pragma once

#include "enemy_state.hpp"

class ShootingEnemy;

class ShootingEnemyTracking : public State<ShootingEnemy>
{
public:
	//void Enter(Player& player);
	void Update(ShootingEnemy& enemy, float dt) override;
	//void Exit(Player& player);
};

class ShootingEnemyHit : public State<ShootingEnemy>
{
public:
	//void Enter(Player& player);
	void Update(ShootingEnemy& enemy, float dt) override;
	//void Exit(Player& player);
private:
	float timer;
};

class ShootingEnemyDying : public State<ShootingEnemy>
{
public:
	//void Enter(Player& player);
	void Update(ShootingEnemy& enemy, float dt) override;
	//void Exit(Player& player);
};