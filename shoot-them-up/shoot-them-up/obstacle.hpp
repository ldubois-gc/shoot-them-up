#pragma once

#include "actor.hpp"

class Obstacle : public Actor
{
public:
	Obstacle(float x, float y, float heigth, float width, sf::Color color, float actorSpeed = 0.f);
	virtual ~Obstacle();

	EntityType Type() override { return EntityType::OBSTACLE; }
	void OnCollision(Entity* collidedEntity) override;
	void Update(float& dt) override;

private:

};

