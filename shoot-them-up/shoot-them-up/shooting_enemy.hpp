#pragma once

#include "enemy.hpp"
#include "shooting_enemy_state.hpp"

class Obstacle;

class ShootingEnemy : public Enemy
{
public:
	ShootingEnemyTracking trackPlayer;
	ShootingEnemyHit enemyHit;
	ShootingEnemyDying killed;

	ShootingEnemy();
	virtual ~ShootingEnemy();

	void Init(float x, float y, float height, float width, sf::Color color, Manager* manager, Player* gamePlayer, std::vector<Obstacle*>* allObstacles, float actorSpeed);
	void OnCollision(Entity* collidedEntity);

	void Movement(float& dt);
	void Update(float& dt);
	void Shoot();
	void StateChange(State<ShootingEnemy>* newState);

private:
	float shootCooldown;
	float shootTimer;
	bool IsAimHittingPlayer();
	bool LineLine(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	StateMachine<ShootingEnemy> stateMachine;

};