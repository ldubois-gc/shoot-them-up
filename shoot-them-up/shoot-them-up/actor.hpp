#pragma once

#include "entity.hpp"

class Actor : public Entity
{
public:
	Actor();
	virtual ~Actor();

	void Move(float x, float y);

private:
	float healthPoints;
};