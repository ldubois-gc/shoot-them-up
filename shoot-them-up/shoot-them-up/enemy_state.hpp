#pragma once

#include "state.hpp"

class Enemy;

class EnemyTracking: public State<Enemy>
{
public:
	//void Enter(Player& player);
	void Update(Enemy& enemy, float dt) override;
	//void Exit(Player& player);
};

class EnemyHit : public State<Enemy>
{
public:
	//void Enter(Player& player);
	void Update(Enemy& enemy, float dt) override;
	//void Exit(Player& player);
private:
	float timer;
};

class EnemyDying: public State<Enemy>
{
public:
	//void Enter(Player& player);
	void Update(Enemy& enemy, float dt) override;
	//void Exit(Player& player);
};