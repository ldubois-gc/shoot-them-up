#pragma once

#include "character.hpp"
#include "actor.hpp"
#include "state.hpp"
#include "player_state.hpp"

class EventHandler;

class Player : public Character
{
public:
	PlayerMoving movement;
	PlayerHit hasBeenHit;
	PlayerDashing dashing;
	PlayerDying dying;

	Player();
	virtual ~Player();

	float GetDirX() { return dirX; }
	float GetDirY() { return dirY; }
	float GetSpeed() { return speed; }
	bool GetInvicible() { return invicible; }
	EventHandler* GetPlayerInput() { return playerInput; };
	StateMachine<Player> GetStateMachine() { return stateMachine; };

	void SetInvicibility(bool invicibility) { invicible = invicibility; };

	EntityType Type() override { return EntityType::PLAYER; }
	void OnCollision(Entity* collidedEntity) override;
	
	void Init(EventHandler* inputManager, float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed);
	using Actor::Update;
	void Update(float& dt) override;

	void Movement(float& dt);
	void Dash(float& dt);
	void Shoot();
	void Invicibility(float& dt);

	void StateChange(State<Player>* newState);

private:
	float dirX;
	float dirY;
	float xAim;
	float yAim;
	float shootCooldown;
	float shootTimer;
	float bleepCooldown;
	float bleepTimer;

	bool invicible;

	EventHandler* playerInput;

	StateMachine<Player> stateMachine;
};