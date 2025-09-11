#include "framework.h"
#include "character.hpp"

Character::Character(float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed) : Actor(x, y, heigth, width, color, actorSpeed)
{
	healthPoints = 20.f;
	gameManager = manager;
}

Character::~Character()
{
}