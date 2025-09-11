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
	
	Player(EventHandler* inputManager, float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed);
	virtual ~Player();

	bool GetInvicible() { return invicible; }
	EventHandler* GetPlayerInput() { return playerInput; };
	StateMachine<Player> GetStateMachine() { return stateMachine; };

	void SetInvicibility(bool invicibility) { invicible = invicibility; };

	using Actor::Update;
	void Update(float& dt) override;

	void Movement(float& dt);
	void Shoot();
	void Invicibility(float& dt);

	void StateChange(State<Player>* newState);

private:
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