#pragma once

#include "character.hpp"
#include "actor.hpp"
#include "state.hpp"

class EventHandler;

class Player : public Character
{
public:
	Player(EventHandler* inputManager, float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed);
	virtual ~Player();

	using Actor::Update;
	void Update(float& dt) override;

	void Shoot();

private:
	float xAim;
	float yAim;
	float shootCooldown;
	float shootTimer;
	EventHandler* playerInput;
	StateMachine<Player> stateMachine;
};