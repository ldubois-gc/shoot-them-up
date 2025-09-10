#pragma once

#include "character.hpp"

class Player;

class Enemy : public Character
{
public:
	Enemy(float x, float y, float heigth, float width, sf::Color color, Manager* manager, Player* gamePlayer, float actorSpeed = 100.f);
	virtual ~Enemy();

	void Update(float& dt) override;

private:
	Player* player;
};