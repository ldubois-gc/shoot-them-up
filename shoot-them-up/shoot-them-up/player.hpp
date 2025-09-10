#pragma once

#include "character.hpp"

class EventHandler;

class Player : public Character
{
public:
	Player(EventHandler* inputManager, float x, float y, sf::Color color, float actorSpeed = 150.f);
	virtual ~Player();

	void Update(float& dt) override;

private:
	EventHandler* playerInput;
};