#pragma once

#include "actor.hpp"

class EventHandler;

class Player : public Actor
{
public:
	Player(EventHandler* inputManager);
	virtual ~Player();

	void Update(float& dt) override;

private:
	EventHandler* playerInput;
};