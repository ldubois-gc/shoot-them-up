#include "framework.h"
#include "hitting_enemy.hpp"
#include "player.hpp"

HittingEnemy::HittingEnemy()
{
}

HittingEnemy::~HittingEnemy()
{
}

void HittingEnemy::Init(float x, float y, float height, float width, sf::Color color, Manager* manager, Player* gamePlayer, std::vector<Obstacle*>* allObstacles, float actorSpeed) {
    Enemy::Init(x, y, height, width, color, manager, gamePlayer, allObstacles, actorSpeed);
}