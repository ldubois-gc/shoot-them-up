#pragma once

#include "actor.hpp"

class EventHandler;

class Player : public Actor
{
public:
	Player(EventHandler* inputManager, float x, float y, sf::Color color, float actorSpeed = 20.f);
	virtual ~Player();

	void Update(float& dt) override;

private:
	EventHandler* playerInput;
};