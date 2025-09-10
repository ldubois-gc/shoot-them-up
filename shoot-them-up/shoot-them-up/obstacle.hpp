#pragma once

#include "actor.hpp"

class Obstacle : public Actor
{
public:
	Obstacle(float x, float y, float heigth, float width, sf::Color color, float actorSpeed = 0.f);
	virtual ~Obstacle();

	void Update(float& dt) override;

private:

};

