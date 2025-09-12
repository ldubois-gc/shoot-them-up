#pragma once

#include "entity.hpp"

class Actor : public Entity
{
public:
	Actor();
	virtual ~Actor();

	float GetSpeed() { return speed; }

	void Move(float x, float y);
	void PushBack(Entity* otherEntity);
	
	virtual EntityType Type() override = 0;
	void OnCollision(Entity* collidedEntity) override;

	void Init(float x, float y, float heigth, float width, sf::Color color, float actorSpeed = 20.f);
	void Update(float& dt) override;

protected:
	float healthPoints;
	float speed;
};