#pragma once

#include "actor.hpp"

class Character;
class Manager;

class Projectile : public Actor
{
public:
	//Projectile(float x, float y, float height, float width, float xDir, float yDir, sf::Color color, Manager* manager, Character* newShooter, float actorSpeed = 20.f);
	Projectile();
	~Projectile();

	Character* GetShooter() { return shooter; }

	EntityType Type() override { return EntityType::PROJECTILE; }
	void OnCollision(Entity* collidedEntity) override;

	void Init(float x, float y, float height, float width, float xDir, float yDir, sf::Color color, Manager* manager, Character* newShooter, float actorSpeed = 20.f);
	void Update(float &dt) override;

private:
	float xForward;
	float yForward;
	Character* shooter;
};