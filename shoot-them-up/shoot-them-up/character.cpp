#include "framework.h"
#include "character.hpp"

Character::Character(float x, float y, float heigth, float width, sf::Color color, float actorSpeed) : Actor(x, y, heigth, width, color, actorSpeed)
{
	healthPoints = 20.f;
}

Character::~Character()
{
}