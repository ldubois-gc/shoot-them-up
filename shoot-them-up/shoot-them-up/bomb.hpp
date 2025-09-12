#pragma once

#include "projectile.hpp"

class Character;
class Manager;

class Bomb : public Projectile
{
public:
	Bomb();
	~Bomb();

	EntityType Type() override { return EntityType::BOMBS; }

	void Explode();

	void Init(float x, float y, float height, float width, float xDir, float yDir, sf::Color color, Manager* manager, Character* newShooter, float actorSpeed);
	//void Update(float& dt) override;

	void OnCollision(Entity* collidedEntity) override;

private:
	float xRange;
	float yRange;
};