#pragma once

#include "actor.hpp"

class Manager;

class Character : public Actor
{
public:
	//Character(float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed = 20.f);
	Character();
	virtual ~Character();

	void Init(float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed = 20.f);

protected:
	float healthPoints;
	Manager* gameManager;
};