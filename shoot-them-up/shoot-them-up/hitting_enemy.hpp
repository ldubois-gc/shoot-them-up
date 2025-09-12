#pragma once

#include "enemy.hpp"

class HittingEnemy : public Enemy
{
public:
	HittingEnemy();
	virtual ~HittingEnemy();

	void Init(float x, float y, float height, float width, sf::Color color, Manager* manager, Player* gamePlayer, std::vector<Obstacle*>* allObstacles, float actorSpeed);

private:

};