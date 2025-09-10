#pragma once

#include "actor.hpp"

class Projectile : public Actor
{
public:
	Projectile();
	~Projectile();

	void Update(float &dt) override;

private:
	float xForward;
	float yForward;
};