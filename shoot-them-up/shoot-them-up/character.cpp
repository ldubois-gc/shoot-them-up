#include "framework.h"
#include "character.hpp"

Character::Character(float x, float y, sf::Color color, float actorSpeed) : Actor(x, y, color, actorSpeed)
{
	healthPoints = 20.f;
}

Character::~Character()
{
}