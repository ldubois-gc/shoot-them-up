#pragma once

#include "entity.hpp"
#include "manager.hpp"

class Actor : public Entity
{
public:
	Actor(float x, float y, sf::Color color, Manager* manager, float actorSpeed);
	Actor(float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed = 20.f);
	virtual ~Actor();

	void Move(float x, float y);
	
	void Update(float& dt) override;

protected:
	float speed;
	Manager* gameManager;
};