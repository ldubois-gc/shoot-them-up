#include "framework.h"
#include "character.hpp"

//Character::Character(float x, float y, float heigth, float width, sf::Color color, Manager* manager, float actorSpeed) : Actor(x, y, heigth, width, color, actorSpeed)
//{
//	healthPoints = 20.f;
//	gameManager = manager;
//}

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