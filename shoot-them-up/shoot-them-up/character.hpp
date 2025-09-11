#pragma once

#include "actor.hpp"

class Character : public Actor
{
public:
	Character(float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed = 20.f);
	virtual ~Character();

protected:
	float healthPoints;
	Manager* gameManager;
};