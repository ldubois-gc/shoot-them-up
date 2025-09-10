#pragma once

#include "character.hpp"
#include "actor.hpp"
#include "state.hpp"

class EventHandler;

class Player : public Character
{
public:
	Player(EventHandler* inputManager, float x, float y, float heigth, float width, sf::Color color, float actorSpeed = 150.f);
	virtual ~Player();

	using Actor::Update;
	void Update(float& dt) override;

	void Shoot(float& xDir, float& yDir);

private:
	EventHandler* playerInput;
	StateMachine<Player> stateMachine;
};