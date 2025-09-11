#pragma once

#include "character.hpp"

class Player;

class Enemy : public Character
{
public:
	//Enemy(float x, float y, float heigth, float width, sf::Color color, Manager* manager, Player* gamePlayer, float actorSpeed = 100.f);
	Enemy();
	virtual ~Enemy();

	EntityType Type() override { return EntityType::ENEMY; }
	void OnCollision(Entity* collidedEntity) override;

	void Init(float x, float y, float height, float width, sf::Color color, Manager* manager, Player* gamePlayer, float actorSpeed = 100.f);
	void Update(float& dt) override;

private:
	Player* player;
};