#include "framework.h"
#include "obstacle.hpp"
#include "actor.hpp"

Obstacle::Obstacle(float x, float y, float heigth, float width, sf::Color color, float actorSpeed) : Actor(x, y, heigth, width, color, actorSpeed)
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::Update(float& dt) {
	
}