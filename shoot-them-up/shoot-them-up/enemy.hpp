#pragma once

#include "character.hpp"
#include "enemy_state.hpp"

class Player;

class Enemy : public Character
{
public:
	EnemyTracking trackPlayer;
	EnemyHit enemyHit;
	EnemyDying killed;

	Enemy();
	virtual ~Enemy();

	EntityType Type() override { return EntityType::ENEMY; }
	void OnCollision(Entity* collidedEntity) override;

	void Movement(float& dt);
	void Init(float x, float y, float height, float width, sf::Color color, Manager* manager, Player* gamePlayer, float actorSpeed = 100.f);
	void Update(float& dt) override;

	void StateChange(State<Enemy>* newState);

private:
	Player* player;
	sf::Vector2f playerDirection;

	float hitCooldown;

	StateMachine<Enemy> stateMachine;
};