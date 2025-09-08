#pragma once

#include "entity.hpp"

class Actor : public Entity
{
public:
	Actor();
	virtual ~Actor();

	float Move(float x, float y);

private:
	float healthPoints;
};