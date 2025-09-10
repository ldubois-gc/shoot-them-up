#pragma once

#include "actor.hpp"

class Projectile : public Actor
{
public:
	Projectile(float x, float y, float xDir, float yDir, sf::Color color, Manager* manager, float actorSpeed = 20.f);
	~Projectile();

	void Update(float &dt) override;

private:
	float xForward;
	float yForward;
};