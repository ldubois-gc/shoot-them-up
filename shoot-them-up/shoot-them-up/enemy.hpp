#pragma once

#include "actor.hpp"

class Enemy : public Actor
{
public:
	Enemy(float x, float y, sf::Color color, float actorSpeed = 10.f);
	virtual ~Enemy();

	void Update(float& dt) override;

private:

};