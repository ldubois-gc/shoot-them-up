#include "framework.h"
#include "character.hpp"

Character::Character()
{
	
}

Character::~Character()
{
}

void Character::Init(float x, float y, float height, float width, sf::Color color, Manager* manager, float actorSpeed) {
	Actor::Init(x, y, height, width, color, actorSpeed);
	healthPoints = 5;
	gameManager = manager;
}