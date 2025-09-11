#include "framework.h"
#include "obstacle.hpp"
#include "actor.hpp"

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle()
{
}

void Obstacle::Init(float x, float y, float height, float width, sf::Color color, float actorSpeed) {
	Actor::Init(x, y, height, width, color, actorSpeed);
}

void Obstacle::Update(float& dt) {
	
}

void Obstacle::OnCollision(Entity* collidedEntity) {
	
}