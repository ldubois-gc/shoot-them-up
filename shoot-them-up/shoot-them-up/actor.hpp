#pragma once

#include "entity.hpp"

class Actor : public Entity
{
public:
	Actor(float x, float y, sf::Color color, float actorSpeed = 20.f);
	virtual ~Actor();

	void Move(float x, float y);
	
	void Update(float& dt) override;

protected:
	float healthPoints;
	float speed;
};